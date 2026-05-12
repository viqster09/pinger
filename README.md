📡 Mini Pinger / Packet Sniffer (C + libpcap)

Un outil simple en C qui capture et affiche les paquets réseau en temps réel (TCP & ICMP uniquement), avec affichage terminal coloré.

⚙️ Fonctionnalités
Capture des paquets réseau en direct
Filtrage TCP et ICMP uniquement
Affichage :
IP source → destination
Ports TCP
Type ICMP
Interface terminal colorée
Basé sur libpcap
🧠 Technologies utilisées
C
libpcap (capture réseau)
Linux (Kali / Ubuntu recommandé)
📦 Installation
1. Installer les dépendances
sudo apt update
sudo apt install libpcap-dev
2. Compiler le programme
gcc pinger.c -o pinger -lpcap
3. Lancer
sudo ./pinger
📸 Capture d’écran

![Pinger Screenshot](Capture_d’écran_2026-05-12_18-10-25.png)

🌈 Exemple de sortie
=========================
IP: 192.168.1.10 -> 8.8.8.8
TCP
Port: 52344 -> 443

=========================
IP: 192.168.1.10 -> 8.8.8.8
ICMP
Type: 8 Code: 0
🔥 Filtres utilisés

Le programme capture uniquement :

ip and (tcp or icmp)
⚠️ Permissions

Le programme nécessite les droits root :

sudo ./pinger
🚀 Améliorations possibles
Interface GUI (GTK)
Statistiques de trafic
Filtrage par port
Export CSV
Graphiques en temps réel
