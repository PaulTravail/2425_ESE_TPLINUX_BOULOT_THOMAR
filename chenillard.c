#include <stdio.h>
#include <unistd.h>

int main() {
    int index_fichier_max = 9;
    char path[64];  
    while(1){

        for (int i = 1; i <= index_fichier_max; i++) {
            
            snprintf(path, sizeof(path), "/sys/class/leds/fpga_led%d/brightness", i);

            // Exemple d'ouverture et de fermeture du fichier
            FILE * outfile = fopen(path, "w");
            if (outfile == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                continue;  // Passer au fichier suivant si erreur
            }

            // Exemple d'écriture dans le fichier
            fprintf(outfile, "1");  // Allumer la LED (1)
            fclose(outfile);
            usleep(50000);

            outfile = fopen(path, "w");
            fprintf(outfile, "0");  // Eteind la LED (0)
            fclose(outfile);
            usleep(50000);           
        }
    }
    return 0;
}