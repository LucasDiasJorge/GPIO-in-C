#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

// Definir o pino dos sensores ópticos

#define SENSOR_A 33
#define SENSOR_B 35


void setEntrada(){

  int i = 0;

  while(i <= 300){

    i++;

    printf("%i",i);

    if ((digitalRead(SENSOR_B)) && i > 50){

      printf("cai entrada\n");
      break;
    }

  }

  delay(500);

}

void setSaida(){

  int i = 0;

  while(i <= 300){

        i++;

        printf("%i",i);

        if ((digitalRead(SENSOR_A)) && i > 50){

            printf("cai saida\n");
            break;
        }

    }

    delay(500);

    }

int main() {

    while(1){

        if(digitalRead(SENSOR_A)){
            printf("Esperando entrada");
            setEntrada();
        }

        if(digitalRead(SENSOR_B)){
            printf("Esperando saida");
            setSaida();
        }

        if(digitalRead(SENSOR_A) && digitalRead(SENSOR_B)){
            while(!digitalRead(SENSOR_A) == LOW || !digitalRead(SENSOR_B == LOW)){
                printf("Ambos sensores dando input ...");
                delay(100);
                }
            }
    }
  return 0;

}