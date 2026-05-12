#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>

#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

void packet_handler(u_char *args,
                    const struct pcap_pkthdr *header,
                    const u_char *packet) {

    struct ip *ip_header = (struct ip*)(packet + 14);

    // 🔥 sécurité : vérifier que c'est bien IP
    if (ip_header->ip_v != 4) return;

    printf("\n=========================\n");

    printf("IP: %s -> %s\n",
           inet_ntoa(ip_header->ip_src),
           inet_ntoa(ip_header->ip_dst));

    // TCP uniquement
    if (ip_header->ip_p == IPPROTO_TCP) {

        struct tcphdr *tcp =
            (struct tcphdr*)(packet + 14 + ip_header->ip_hl * 4);

        printf(BLUE "TCP\n" RESET);
        printf(BLUE "Port: %d -> %d\n" RESET,
               ntohs(tcp->th_sport),
               ntohs(tcp->th_dport));
    }

    // ICMP uniquement
    else if (ip_header->ip_p == IPPROTO_ICMP) {

        struct icmphdr *icmp =
            (struct icmphdr*)(packet + 14 + ip_header->ip_hl * 4);

        printf(RED "ICMP\n" RESET);
        printf(RED "Type: %d Code: %d\n" RESET,
               icmp->type,
               icmp->code);
    }
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    char *device = alldevs->name;

    printf("Listening on: %s\n", device);

    pcap_t *handle = pcap_open_live(device, 65536, 1, 1000, errbuf);

    if (!handle) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // 🔥 FILTRE STRICT
    struct bpf_program fp;
    char filter_exp[] = "ip and (tcp or icmp)";

    pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &fp);

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(alldevs);
    pcap_close(handle);

    return 0;
}