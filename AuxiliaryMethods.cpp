#include "AuxiliaryMethods.h"


int AuxiliaryMethods::loadInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest numer. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::getNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int AuxiliaryMethods::stringToIntConversion(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::intToStringConversion(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::loadChar() {
    string input = "";
    char singleCharacterLoaded  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            singleCharacterLoaded = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return singleCharacterLoaded;
}

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

