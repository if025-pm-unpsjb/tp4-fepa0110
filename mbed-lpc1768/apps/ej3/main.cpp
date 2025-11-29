#include "mbed.h"

DigitalOut led1(LED1);

Serial serial(USBTX, USBRX, 9600);

char echo;
int main() {
    serial.printf("Echoes back to the screen anything you type\n");
    while(1) {
        serial.printf("%c\r\n", serial.getc());
    }
}
