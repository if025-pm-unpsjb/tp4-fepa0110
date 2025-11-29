#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

DigitalOut leds[4] = { led1, led2, led3, led4 };

Serial serial(USBTX, USBRX, 9600);
int incremento = 0;
char entrada[4];

void callback() { }

int main()
{
    while (incremento <= 0) {
        serial.printf("Ingrese el incremento en mS: ");
        serial.scanf("%d", &incremento);
        serial.putc(incremento);
    }

	serial.printf("Iniciando...");

    while (1) {
        for (int cuenta = 0; cuenta <= 15; cuenta++) {
            led1 = cuenta & 0b0001;
            led2 = cuenta & 0b0010;
            led3 = cuenta & 0b0100;
            led4 = cuenta & 0b1000;
            wait(incremento / 1000);
        }

		if(serial.readable()){
			serial.gets(entrada, 4);
			incremento = (int)entrada;
		}
    }
}
