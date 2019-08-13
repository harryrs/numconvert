# numconvert

Program to convert positive numbers in the range [0, 2^31)
from decimal to binary

Once the file has been added to your directory, compile and
run from the command line with the following command:

    gcc numconvert.c -lm -std=c99 -o numconvert
    ./numconvert [number] <convert_from> <convert_to>

The <convert_from> and <convert_to> flags should be one of -b,
-x, or -d for binary, hex, or decimal respectively.

This program was created mainly as a sample of how I like to
solve problems using code. This program was inspired by my
struggles with converting numbers between decimal, binary,
and hexadecimal in my computer organization class in college.
All of the projects for said class had to be written in C, so
I figured I would follow suit as well as add a little extra
challenge for this project by writing it in C rather than my
preferred language, C++.

Happy converting! :)

UPDATE 11 August 2019
This project is small but I am still working on it! I set a
goal to implement support for negative numbers, as well as
conversion from binary back to decimal by the end of August.
This project came to a hard halt when I started getting into
the thick of my coursework and then immediately had to focus on
moving and starting my internship, but I'd like to keep working
on it alongside a few other personal projects I've had in mind.
