# 2425_ESE_TPLINUX_BOULOT_THOMAR

### 1.3 Connexion au système

## 1.3.2 Utilisez un logiciel de liaison série

L’image copiée précédemment n’occupe pas la totalité de la carte SD. Quelle est la taille occupée ?
<p align="center"> <img src="Img/df -h.png" width="60%" height="auto" /> </p>
Comme on peut le voir, seulement 3 Go de la carte SD sont occupés.

Vérifiez que vous avez bien 32GB de disponible sur la carte SD.
<p align="center"> <img src="Img/df -h2.png" width="60%" height="auto" /> </p>
Comme on peut le voir, on utilise désormais 14GB sur la carte. (notre carte SD fait 16GB)

## 1.3.3 Configuration réseau

### 1.4 Découverte de la cible

## 1.4.1 Exploration des dossiers /sys/class et /proc

cat cpuinfo donne les informations sur les processeurs présents sur la cible.

cat ioports ne montre rien car le fichier est vide sous linux.

cat iomem montre ce qui est présent dans la mémoire en nous précisant l'adresse et ce qu'elle contient.

## 1.4.2 Compilation croisée

On préfère compiler sur notre pc plutôt que sur le gcc du SoC pour une question de performance. On utilise donc une compilation croisée, les programmes sont compilée sur notre pc et on copie juste l'executable sur le SoC.

## 1.4.3 Hello world !

## 1.4.5 Chenillard (Et oui, encore !)

```C
#include <stdio.h>
#include <unistd.h>

int main() {
    int index_fichier_max = 9;
    char path[64];  
    while(1){

        for (int i = 1; i <= index_fichier_max; i++) {    //on commence à la led 1 car la led 0 clignote déjà
            
            snprintf(path, sizeof(path), "/sys/class/leds/fpga_led%d/brightness", i);

            // Exemple d'ouverture et de fermeture du fichier
            FILE * outfile = fopen(path, "w");
            if (outfile == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                continue;  // Passer au fichier suivant si erreur
            }

            // Ecriture dans le fichier

            fprintf(outfile, "1");  // Allumer la LED (1)
            fclose(outfile);
            usleep(50000);

            outfile = fopen(path, "w");
            fprintf(outfile, "0");  // Eteindre la LED (0)
            fclose(outfile);
            usleep(50000);           
        }
    }
    return 0;
}
```

### 2.1 Accès aux registres

Depuis l'espace utilisateur, le programme ne peut pas modifier tous les registres et son espace mémoire est limité.

