#include "FileWithUsers.h"


vector <User> FileWithUsers::loadUsersFromFile() {

    User user;
    string oneUserDataSeparatedByVerticalBars = "";
    vector <User> users;
    fstream textFile;

    textFile.open(FILE_NAME.c_str(), ios::in);
    if (textFile.good() == true) {
        while (getline(textFile, oneUserDataSeparatedByVerticalBars)) {
            user = getUserData(oneUserDataSeparatedByVerticalBars);
            users.push_back(user);
        }

    }
    textFile.close();

    return users;
}

User FileWithUsers::getUserData(string oneUserDataSeparatedByVerticalBars) {

    User user;
    string paftOfUserData = "";
    int numberOfPartUserData = 1;

    for (int charPosition = 0; charPosition < oneUserDataSeparatedByVerticalBars.length(); charPosition++) {
        if (oneUserDataSeparatedByVerticalBars[charPosition] != '|') {
            paftOfUserData += oneUserDataSeparatedByVerticalBars[charPosition];
        } else {
            switch(numberOfPartUserData) {
            case 1:
                user.setId(atoi(paftOfUserData.c_str()));
                break;
            case 2:
                user.setLogin(paftOfUserData);
                break;
            case 3:
                user.setPassword(paftOfUserData);
                break;
            }
            paftOfUserData = "";
            numberOfPartUserData++;
        }
    }
    return user;
}


void FileWithUsers::addUserToFile(User user) {

    string lineWithUserData = "";
    fstream textFile;

    textFile.open(FILE_NAME.c_str(), ios::app);
    if (textFile.good() == true) {
        lineWithUserData = replaceUserDataForStringSeparatedByVerticalBars(user);

        if (isEmpty(textFile) == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << FILE_NAME << " i zapisac w nim danych." << endl;
    textFile.close();
}

string FileWithUsers::replaceUserDataForStringSeparatedByVerticalBars(User user) {

    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethods::intToStringConversion(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

void FileWithUsers::addAllUsersToFile(vector <User> users) {

    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILE_NAME.c_str(), ios::out);
    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = replaceUserDataForStringSeparatedByVerticalBars(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << FILE_NAME << endl;
    }
    textFile.close();
}

