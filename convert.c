/**
 *
 * Number Converter
 *
 * Program to convert numbers from decimal to
 * 32-bit binary number (potential future edits
 * include two's complement, conversions from
 * decimal to hex, and converting binary and/or
 * hex numbers to decimal)
 *
 * Written by Harry Silverman, as a means of
 * procrastinating his actual assignments
 *
 **/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("usage: ./convert [number]\n");
	    exit(1);
    }
    int num = atoi(argv[1]);
    if (num < 0) {
        printf("program currently only supports conversion ");
        printf("of positive numbers to 32-bit binary\n");
        exit(1);
    }
    int bits[32];        // The C programming language cannot support integers as big or bigger than
    int bitsNeeded = 0;  // 2^31, so neither can this program

    while (num > 0) {

        bits[bitsNeeded] = num & 1;   // get current bit and put in appropriate array index
        num = num / 2;                // equivalent to num = num >> 1, or bit-shifting right by one
        bitsNeeded = bitsNeeded + 1;  // update index
    }
    if (bitsNeeded == 0) {

        printf("%d", bitsNeeded);
    }
    else {
        // printing from left-to-write for output readability
        for (int i = bitsNeeded - 1; i >= 0; i = i - 1) {

            printf("%d", bits[i]);
        }
    }
    printf("\n");
    return 0;
}
