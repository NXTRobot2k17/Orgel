#include "AsciiConverter.h"

AsciiConverter::AsciiConverter()
{
    //ctor
}

AsciiConverter::~AsciiConverter()
{
    //dtor
}
int AsciiConverter::convert(char c)
{
    int i = 0;
    switch(c)
    {
        case 'z': i = 0;
        break;
        case '7': i = 1;
        break;
        case 'u': i = 2;
        break;
        case 'i': i = 3;
        break;
        case '9': i = 4;
        break;
        case 'o': i = 5;
        break;
        case '0': i = 6;
        break;
        case 'p': i = 7;
        break;
        case 'ü': i = 8;
        break;
        case '´': i = 9;
        break;
        case '+': i = 10;
        break;
        case '6': i = -1;
        break;
        case 't': i = -2;
        break;
        case '5': i = -3;
        break;
        case 'r': i = -4;
        break;
        case 'e': i = -5;
        break;
        case '3': i = -6;
        break;
        case 'w': i = -7;
        break;
        case '2': i = -8;
        break;
        case 'q': i = -9;
        break;
        case 'm': i = -10;
        break;
        case 'j': i = -11;
        break;
        case 'n': i = -12;
        break;
        case 'h': i = -13;
        break;
        case 'b': i = -14;
        break;
        case 'g': i = -15;
        break;
        case 'v': i = -16;
        break;
        case 'c': i = -17;
        break;
        case 'd': i = -18;
        break;
        case 'x': i = -19;
        break;
        case 's': i = -20;
        break;
        case 'y': i = -21;
    }
    return i;
}
