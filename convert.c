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
    int bits[32];
    int bitsNeeded = 0;

    while (num > 0) {

        int one = 1;
        if ((num & 1) == 1) {

            bits[bitsNeeded] = 1;
        }
        else {

            bits[bitsNeeded] = 0;
        }
        num = num / 2;
        bitsNeeded = bitsNeeded + 1;
    }
    if (bitsNeeded == 0) {

        printf("%d", bitsNeeded);
    }
    else {

        for (int i = bitsNeeded - 1; i >= 0; i = i - 1) {

            printf("%d", bits[i]);
        }
    }
    printf("\n");

    return 0;
}
