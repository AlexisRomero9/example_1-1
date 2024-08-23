#include "mbed.h"
#include "arm_book_lib.h"

//Autores: Romero Espinoza Alexis, Sosa Gabriel

int main()
{
    DigitalIn gasDetector(D2);       //Es una instancia de la clase DigitalIn, que es el pin(D2) en el cual se conecta el pulsador
    DigitalIn gasDetector2(BUTTON1); //BUTTON1 es el boton integrado en la placa STM32F429ZI

    //Son los LEDs integrados en la placa, que se setean como salida
    DigitalOut alarmLed(LED1); 
    DigitalOut alarmLed2(LED2);

    //El modo PullDown se utiliza para habilitar la resistencia de PullDown, que setea el pin a estado bajo
    gasDetector.mode(PullDown);
    gasDetector2.mode(PullDown);

    //Estados iniciales de los LEDs
    alarmLed = OFF;
    alarmLed2 = ON;

    //printf("%s\n","Hello World"); //Al agregar la linea fuera del while, en el monitor serie se verá una sola vez la linea "Hello World"

    while (true) {

        printf("%s\n","Hello World"); //Al agregar la linea de código dentro del while se observa en el monitor serial
                                      // constantemente la linea "Hello World"

        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }

        if ( gasDetector2 == ON ) {
            alarmLed2 = OFF;
        }
        
        if ( gasDetector2 == OFF ) {
            alarmLed2 = ON;
        }
    }
}