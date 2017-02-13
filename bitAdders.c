/*

bitAdders.c

(c) Copyright 2017 Eric Sund

This file lets you use the implementations of the bit adder functions
Call on any function you'd like from bitAddes.h header file inside the main
Example is provided here for you

*/

#include <stdio.h>
#include "bitAdders.h"

int main() {
	//Add bits 0 and 1 with an HA
	adderReturn p = halfAdder(0, 1);

	//Add bits 1 and 0 with an FA
	adderReturn q = fullAdder(1, 0, 0);

	//Add 0xA and 0x3 with a full bit adder array
	adderReturn r = fourBitAdder(0xA, 0x3, 0x0);

	//Output each sum in hexadecimal
	//Use %d for base 10 if you prefer
	printf("p's sum is: %x\n", p.sum);
	printf("q's sum is: %x\n", q.sum);
	printf("r's sum is: %X\n", r.sum);

	return 0;
}
