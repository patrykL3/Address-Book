#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <sstream>
#include <iostream>

using namespace std;


class AuxiliaryMethods {

public:

    static string intToStringConversion(int number);
    static int stringToIntConversion(string number);
    static int loadInteger();
    static char loadChar();
    static string loadLine();
    static string getNumber(string text, int charPosition);
};


#endif
