# numconvert

Program to convert positive numbers in the range [0, 2^31)
between decimal, binary, and hexadecimal. Future additions
to this program might include support for negative numbers
and the conversion of the program to C++ to improve clarity
and efficiency.

## Getting Started

The project is super simple at this stage, and all that needs
to be done is fork the repository, clone it and compile/run on
your local machine.

### Prerequisites

You will need a C compiler, ideally GCC, installed to be able
to compile and run the program. If you don't, [here](https://www.guru99.com/c-gcc-install.html) is a
tutorial for downloading/installing GCC on Windows, Mac, and
Linux.

Once you have GCC installed and have the repository cloned on
your local machine, compile and run with the following commands:

    gcc numconvert.c -lm -std=c99 -o numconvert
    ./numconvert [number] <convert_from> <convert_to>

The <convert_from> and <convert_to> flags should be one of -b,
-x, or -d for binary, hex, or decimal respectively.

## Project Background

This program was created mainly as a sample of how I like to
solve problems using code. This program was inspired by my
struggles with converting numbers between decimal, binary,
and hexadecimal in my computer organization class in college.
All of the projects for said class had to be written in C, so
I figured I would follow suit as well as add a little extra
challenge for this project by writing it in C rather than my
preferred language, C++.

Happy converting! :)
