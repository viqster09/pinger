============================================================
⚡ PROJET : PingerX — Sniffer Réseau Bas Niveau (C / libpcap)
============================================================

AUTEUR : [Ton Nom]
STACK : C | libpcap | Linux
TYPE : Réseau / Cybersécurité / Systèmes bas niveau

============================================================
🎯 PRÉSENTATION DU PROJET
============================================================

PingerX est un outil léger de capture de paquets réseau en temps réel,
développé en langage C avec la bibliothèque libpcap.

Il permet d’analyser le trafic réseau directement depuis une interface
réseau et de visualiser les communications TCP et ICMP.

Ce projet a été réalisé dans le but de comprendre le fonctionnement
interne des réseaux informatiques et du modèle TCP/IP.

============================================================
🧠 OBJECTIFS DU PROJET
============================================================

- Comprendre la structure des paquets réseau
- Apprendre la capture de paquets avec libpcap
- Analyser les en-têtes IP, TCP et ICMP manuellement
- Reproduire un outil type Wireshark en version simplifiée
- Travailler proche du fonctionnement système (bas niveau)

============================================================
⚙️ FONCTIONNALITÉS
============================================================

✔ Capture réseau en temps réel
✔ Détection des paquets TCP avec ports source/destination
✔ Détection des paquets ICMP (ping)
✔ Affichage des IP source → destination
✔ Filtrage des protocoles (TCP + ICMP uniquement)
✔ Interface terminal simple et rapide
✔ Outil léger et performant

============================================================
🛠️ TECHNOLOGIES UTILISÉES
============================================================

- Langage C
- libpcap (capture de paquets réseau)
- Système Linux (Kali / Ubuntu recommandé)
- Analyse bas niveau du protocole TCP/IP

============================================================
📡 FONCTIONNEMENT
============================================================

1. Le programme ouvre une interface réseau via libpcap
2. Il passe en mode écoute (promiscuous mode)
3. Un filtre est appliqué :
       ip and (tcp or icmp)
4. Chaque paquet capturé est envoyé à une fonction callback
5. Le paquet est analysé :
       Ethernet → IP → TCP / ICMP
6. Les résultats sont affichés en temps réel dans le terminal

============================================================
📸 CAPTURE D’ÉCRAN
============================================================

Markdown GitHub :
![PingerX](Capture_d’écran_2026-05-12_18-10-25.png)

============================================================
📦 INSTALLATION
============================================================

1. Installer les dépendances :
""
   sudo apt update
   sudo apt install libpcap-dev
""
2. Compiler le programme :

   gcc pinger.c -o pinger -lpcap

3. Lancer le programme (root obligatoire) :

   sudo ./pinger

============================================================
📤 EXEMPLE DE SORTIE
============================================================

=========================
IP : 192.168.1.10 -> 8.8.8.8
PROTOCOLE : TCP
PORT : 52344 -> 443

=========================
IP : 192.168.1.10 -> 8.8.8.8
PROTOCOLE : ICMP
TYPE : 8 CODE : 0

============================================================
🔍 FILTRE UTILISÉ
============================================================

ip and (tcp or icmp)

============================================================
⚠️ PRÉREQUIS
============================================================

- Système Linux (Kali / Ubuntu recommandé)
- Droits administrateur (sudo)
- libpcap installé

============================================================
📚 CE QUE J’AI APPRIS
============================================================

- Structure des paquets réseau (Ethernet / IP / TCP / ICMP)
- Fonctionnement du sniffing réseau
- Analyse de trafic en temps réel
- Compréhension du fonctionnement de Wireshark
- Programmation système en C bas niveau

============================================================
🚀 AMÉLIORATIONS POSSIBLES
============================================================

- Interface graphique (GTK / Qt)
- Statistiques réseau en temps réel
- Export des données (CSV / JSON)
- Filtres avancés (ports, IP spécifiques)
- Visualisation graphique du trafic
- Interface terminal avancée (type dashboard)

============================================================
🧠 AVERTISSEMENT
============================================================

Ce projet est à but strictement éducatif.
Il doit être utilisé uniquement sur des réseaux personnels
ou autorisés.

============================================================
