#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define LED 22
#define BUTTON 21

int main() {

    if (wiringPiSetup() == -1) {
      fprintf(stderr, "Falha ao inicializar a biblioteca WiringPi\n");
      exit(1);
    }

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);

    while(1) {
        if (digitalRead(BUTTON) == HIGH) {
            digitalWrite(LED, HIGH);
            printf("LED ligado\n");
        } else {
            digitalWrite(LED, LOW);
            printf("LED desligado\n");
        }
    }

    return 0;
}
