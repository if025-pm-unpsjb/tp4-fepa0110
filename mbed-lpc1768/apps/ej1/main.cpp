#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
	while(1){
		for(int cuenta = 0; cuenta <= 15; cuenta++){
			led1 = cuenta & 0b0001;
			led2 = cuenta & 0b0010;
			led3 = cuenta & 0b0100;
			led4 = cuenta & 0b1000;
			wait(1);
		}

	}
}
