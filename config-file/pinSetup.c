#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

// Definições para os pinos, inicialmente com valores padrão
int LED_R = 1;
int LED_G = 2;
int BUTTON = 3; 
int PHOTO_TRANSISTOR = 4;
int PULSE = 5;
int RELEY = 6;

void debugging(const char *message) {
    printf("%s\n", message);
}

// Ler o arquivo antes de configurar os pinos
void readConfigFile() {
    FILE *file = fopen("config/config.cfg", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char key[50];
        int value;

        // Parseia cada linha no formato "CHAVE=VALOR"
        if (sscanf(line, "%49[^=]=%d", key, &value) == 2) {
            if (strcmp(key, "LED_R") == 0) {
                LED_R = value;
            } else if (strcmp(key, "LED_G") == 0) {
                LED_G = value;
            } else if (strcmp(key, "BUTTON") == 0) {
                BUTTON = value;
            } else if (strcmp(key, "PHOTO_TRANSISTOR") == 0) {
                PHOTO_TRANSISTOR = value;
            } else if (strcmp(key, "PULSE") == 0) {
                PULSE = value;
            } else if (strcmp(key, "RELEY") == 0) {
                RELEY = value;
            }
        }
    }

    fclose(file);
}

int pinSetup(){

    wiringPiSetupGpio();

    if (wiringPiSetup() == -1) {
      debugging("Falha ao iniciar wiringPi");
      exit(1);
    }

    readConfigFile();

    debugging("Setting pins");

    // output set
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(RELEY, OUTPUT);
    pinMode(PULSE, OUTPUT);

    // input set
    pinMode(PHOTO_TRANSISTOR, INPUT);
    pinMode(BUTTON, INPUT);

    debugging("Pins are setted");

    return 0;
}