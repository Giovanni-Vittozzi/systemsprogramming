//By: Giovanni Vittozzi
//Blinks 2 LEDS
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include <bcm2835.h>
#include <stdio.h>

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11 //pin for first LED (Pin 17)
#define PIN2 RPI_GPIO_P1_12 //pin for second LED (Pin 18)


int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    // Set the pins to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);

    // printf("getchar in while %c", character_read);
    // Blink

    
    int car;
    
    do{
	//printf("getchar in while %c\n", character_read);
        bcm2835_gpio_write(PIN, HIGH); //turn on one LED
	bcm2835_gpio_write(PIN2, LOW);	//Keep other LED off

	// wait a bit
	bcm2835_delay(500);
	
	bcm2835_gpio_write(PIN, LOW); //turn off first LED 
	bcm2835_gpio_write(PIN2,HIGH); //turn on second LED

	// wait a bit
	bcm2835_delay(500);
	car= getchar();
	
        //char c[10];
	//printf("%c\n", c);
       	//if(car == '\n'){
	//	break;
	//}
	//else{}
	 	
    }while(car != '\n');

    bcm2835_gpio_write(PIN2, LOW);
    bcm2835_gpio_write(PIN, LOW);

    bcm2835_close();
    return 0;
}

