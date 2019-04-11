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
    unsigned int bit = 1 << 31; // C cannot support integers that are more than 32 bits
    int shifted = 31;

    // Optimization for the edge case where num is 0
    if (num == 0) {
        printf("%d", 0);
        return 0;
    }
    // Find the most significant, non-zero bit
    while (!(bit & num)) {
        shifted -= 1;
        bit = bit >> 1;
    }
    while (bit > 0) {

        // Get the current bit, print it, and move to 
        // next-most-significant bit
        int temp = (bit & num) >> shifted;
        printf("%d", temp);
        shifted -= 1;
        bit = bit >> 1;
    }
    printf("\n");
    return 0;
}