# 2425_ESE_TPLINUX_BOULOT_THOMAR

### 1.3 Connexion au système

## 1.3.2 Utilisez un logiciel de liaison série

L’image copiée précédemment n’occupe pas la totalité de la carte SD. Quelle est la taille occupée ?
<p align="center"> <img src="Img/df -h.png" width="60%" height="auto" /> </p>
Comme on peut le voir, seulement 3 Go de la carte SD sont occupés.

Vérifiez que vous avez bien 32GB de disponible sur la carte SD.
<p align="center"> <img src="Img/df -h2.png" width="60%" height="auto" /> </p>
Comme on peut le voir, on utilise désormais 14GB sur la carte.

## 1.3.3 Configuration réseau

### 1.4 Découverte de la cible

cat cpuinfo donne les informations sur les processeurs présents sur la cible.

cat ioports ne montre rien car le fichier est vide sous linux.

cat iomem montre ce qui est présent dans la mémoire en nous précisant l'adresse et ce qu'elle contient.

### 2.1 Accès aux registres

Les processus ne peuvent pas partager les registres, lorsqu’un changement de processus
survient, le contexte matériel est sauvegardé dans la pile système.
