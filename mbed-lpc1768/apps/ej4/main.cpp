#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

DigitalOut leds[4] = { led1, led2, led3, led4 };

Serial serial(USBTX, USBRX, 9600);

int indiceLed = 0;

int main() {
	while (indiceLed < 1 || indiceLed > 4) {
		serial.printf("Ingrese el LED que sea parpadear: ");
		serial.scanf("%d", &indiceLed);
		serial.putc(indiceLed);
	}

	serial.printf("Iniciando...");

	while (1) {
		leds[indiceLed - 1].write(0);
		wait(250);
		leds[indiceLed - 1].write(1);
		wait(250);
	}
}
