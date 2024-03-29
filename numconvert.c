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

void decimal_to_binary(char* num);
int binary_to_decimal(char* num);

void decimal_to_hex(char* num);
int hex_to_decimal(char* num);

void hex_to_binary(char* num);
void binary_to_hex(char* num);

int main(int argc, char* argv[]) {

    if (argc < 2 || argc > 4 || argc == 3) {
        printf("usage: ./numconvert <number> <convert_from> <convert_to>\n");
        printf("Enter ./numconvert --help for more information\n");
	    exit(1);

    } else if (argc == 2) {

        if (strcmp(argv[1], "--help") == 0) {
            printf("./numconvert\n");
            printf("<number>          The number you would like to convert\n");
            printf("<convert_from>    Numeral system of <number> (-b for binary, -x for hex, -d for decimal)\n");
            printf("<convert_to>      Numeral system to convert to (-b for binary, -x for hex, -d for decimal)\n");
            exit(1);

        } else {
            printf("usage: ./numconvert <number> <convert_from> <convert_to>\n");
            printf("Enter ./numconvert --help for more information\n");
	        exit(1);
        }
    }

    if (!(strcmp(argv[2], "-b") == 0 || strcmp(argv[2], "-x") == 0 || strcmp(argv[2], "-d") == 0) ||
        !(strcmp(argv[3], "-b") == 0 || strcmp(argv[3], "-x") == 0 || strcmp(argv[3], "-d") == 0)) {
        
        printf("Error: <convert_from> and <convert_to> arguments must be one of -b, -x, or -d\n");
        printf("Enter ./numconvert --help for more information\n");
        exit(1);
    }

    if (strcmp(argv[2], "-b") == 0) {

        if (strcmp(argv[3], "-x") == 0) {

            binary_to_hex(argv[1]);

        } else if (strcmp(argv[3], "-d") == 0) {

            binary_to_decimal(argv[1]);

        } else {

            printf("%s", argv[1]);
        }
    } else if (strcmp(argv[2], "-x") == 0) {

        if (strcmp(argv[3], "-b") == 0) {

            hex_to_binary(argv[1]);

        } else if (strcmp(argv[3], "-d") == 0) {

            hex_to_decimal(argv[1]);

        } else {

            printf("%s", argv[1]);
        }
    } else {

        if (strcmp(argv[3], "-b") == 0) {

            decimal_to_binary(argv[1]);

        } else if (strcmp(argv[3], "-x") == 0) {

            decimal_to_hex(argv[1]);

        } else {

            printf("%s", argv[1]);
        }
    }
    printf("\n");
    return 0;
}

void decimal_to_binary(char* num) {

    int number = atoi(num);
    if (number < 0) {
        printf("program currently only supports conversion ");
        printf("of positive numbers to 32-bit binary\n");
        exit(1);
    }

    unsigned int bit = 1 << 31;
    int shifted = 31;

    // Optimization for the edge case where num is 0
    if (num == 0) {
        printf("%d", 0);
        return;
    }

    // Find the most significant, non-zero bit
    while (!(bit & number)) {
        shifted -= 1;
        bit = bit >> 1;
    }

    while (bit > 0) {

        // Get the current bit, print it, and move to 
        // next-most-significant bit
        int temp = (bit & number) >> shifted;
        printf("%d", temp);
        shifted -= 1;
        bit = bit >> 1;
    }
}

int binary_to_decimal(char* num) {
    
    int number = 0;
    for (int i = 0; num[i] != '\0'; i += 1) {

        if (!(num[i] == '0' || num[i] == '1')) {

            printf("Error: invalid binary number\n");
            exit(1);
        }
        number = number << 1;
        number = num[i] == '1' ? number + 1 : number;
    }
    printf("%d", number);

    return number;
}

void decimal_to_hex(char* num) {

    int number = atoi(num);
    if (number < 0) {
        printf("program currently only supports conversion ");
        printf("of positive numbers to 32-bit binary\n");
        exit(1);
    }
    printf("%x", number); // Not going to reinvent the wheel here
}

int hex_to_decimal(char* num) {
    
    int number = 0;
    int bits = 0;
    for (int i = 0; num[i] != '\0'; i += 1) {

        number = number << 4;
        if (num[i] >= '0' && num[i] <= '9') {

            bits = ((int)num[i]) - 48;

        } else if (num[i] >= 'a' && num[i] <= 'f') {

            bits = ((int)num[i]) - 87;

        } else {

            printf("Error: invalid hexadecimal number (please enter a - f as lower-case)\n");
            exit(1);
        }
        number = number | bits;
    }
    printf("%d", number);
    return number;
}

void hex_to_binary(char* num) {
    
    // Want to do this check before printing anything
    for (int i = 0; num[i] != '\0'; i += 1) {

        if (!(num[i] >= '0' && num[i] <= '9') && !(num[i] >= 'a' && num[i] <= 'f')) {

            printf("Error: invalid hexadecimal number (please enter a - f as lower-case)\n");
            exit(1);
        }
    }

    for (int i = 0; num[i] != '\0'; i += 1) {

        // More efficient than converting back to decimal and then to binary
        int bits = 0;
        unsigned int bit_to_print = 0b1000;
        int shifted = 3;

        if (num[i] >= '0' && num[i] <= '9') {

            bits = ((int)num[i]) - 48;

        } else if (num[i] >= 'a' && num[i] <= 'f') {

            bits = ((int)num[i]) - 87;
        }
        while (bit_to_print > 0) {

            printf("%d", (bits & bit_to_print) >> shifted);
            shifted = shifted >> 1;
        }
    }
}

void binary_to_hex(char* num) {
    
    // Might as well just reuse functionality that's already been implemented
    int number = binary_to_decimal(num);
    printf("%x", number);
}