#include "mbed.h"

PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

PwmOut leds[4] = { led1, led2, led3, led4 };

int indiceLed = 0;

int main() {
	while (1) {
		for (float intensidad = 0.0f; intensidad <= 1.0f; intensidad += 0.05f) {
			leds[indiceLed].write(intensidad);
			wait(0.01);
		}

		wait(1);

		for (float intensidad = 1.0f; intensidad >= 0.0f; intensidad -= 0.05f) {
			leds[indiceLed].write(intensidad);
			wait(0.01);
		}
		leds[indiceLed].write(0);

		if (indiceLed < 3)
			indiceLed++;
		else
			indiceLed = 0;

	}
}

