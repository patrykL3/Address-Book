#include "FileWithRecipients.h"


void FileWithRecipients::updateSelectedRecipientsDataInFile(Recipient recipient) {

    string lineWithUpdatedRecipientData = "";
    string loadedLine = "";
    string tempFileNameWithRecipients = FILE_NAME + "_TEMP";
    fstream textFile;
    fstream tempTextFile;
    int recipientIdFromRecentlyReadLine = 0;
    bool firstLoadedLine = true;

    lineWithUpdatedRecipientData = replaceRecipientDataForStringSeparatedByVerticalBars(recipient);

    textFile.open(FILE_NAME.c_str(), ios::in);
    tempTextFile.open(tempFileNameWithRecipients.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        while (getline(textFile, loadedLine)) {
            recipientIdFromRecentlyReadLine = getRecipientIdFromDataSeparatedByVerticalBars(loadedLine);
            if (recipientIdFromRecentlyReadLine != recipient.getRecipientId() && firstLoadedLine == false)
                tempTextFile << endl << loadedLine;
            else if (recipientIdFromRecentlyReadLine != recipient.getRecipientId() && firstLoadedLine == true) {
                tempTextFile << loadedLine;
                firstLoadedLine = false;
            } else if (recipientIdFromRecentlyReadLine == recipient.getRecipientId() && firstLoadedLine == true) {
                tempTextFile << lineWithUpdatedRecipientData;
                firstLoadedLine = false;
            } else if (recipientIdFromRecentlyReadLine == recipient.getRecipientId() && firstLoadedLine == false) {
                tempTextFile << endl << lineWithUpdatedRecipientData;
            }
        }
        textFile.close();
        tempTextFile.close();

        deleteFile(FILE_NAME);
        changeFileName(tempFileNameWithRecipients, FILE_NAME);
    }
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void FileWithRecipients::deleteRecipientInFile(int deleteRecipientId) {

    fstream textFile;
    fstream tempTextFile;
    string loadedLine = "";
    string tempFileNameWithRecipients = FILE_NAME + "_TEMP";
    bool firstLoadedLine = true;
    int recipientIdFromRecentlyReadLine = 0;
    int largestRecipientIdThatWillNotBeDeleted = 0;

    textFile.open(FILE_NAME.c_str(), ios::in);
    tempTextFile.open(tempFileNameWithRecipients.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        while (getline(textFile, loadedLine)) {
            recipientIdFromRecentlyReadLine = getRecipientIdFromLine(loadedLine);

            if (recipientIdFromRecentlyReadLine != deleteRecipientId && firstLoadedLine == false) {
                tempTextFile << endl << loadedLine ;
                largestRecipientIdThatWillNotBeDeleted = getRecipientIdFromDataSeparatedByVerticalBars(loadedLine);
            } else if (recipientIdFromRecentlyReadLine != deleteRecipientId && firstLoadedLine == true) {
                tempTextFile << loadedLine ;
                firstLoadedLine = false;
                largestRecipientIdThatWillNotBeDeleted = getRecipientIdFromDataSeparatedByVerticalBars(loadedLine);
            } else if(recipientIdFromRecentlyReadLine == deleteRecipientId && recipientIdFromRecentlyReadLine == lastRecipientId) {
                lastRecipientId = largestRecipientIdThatWillNotBeDeleted;
            }
        }

        textFile.close();
        tempTextFile.close();

        deleteFile(FILE_NAME);
        changeFileName(tempFileNameWithRecipients, FILE_NAME);
    }
}

int FileWithRecipients::getRecipientIdFromLine(string loadedLine) {

    string recipientIdFromLine = "";

    for (int charPosition = 0; charPosition < loadedLine.length(); charPosition++) {

        if (loadedLine[charPosition] != '|')
            recipientIdFromLine += loadedLine[charPosition];
        else
            break;
    }

    return AuxiliaryMethods::stringToIntConversion(recipientIdFromLine);
}

int FileWithRecipients::getLastRecipientId() {

    return lastRecipientId;
}

vector<Recipient> FileWithRecipients::loadRecipientsOfLoggedUserFromFile(int LOGGED_USER_ID) {

    vector<Recipient> recipients;
    Recipient recipient;
    string dataOfOneRecipientSeparatedByVerticalBars = "";
    string dataOfLastRecipientInFile = "";
    fstream textFile;
    textFile.open(FILE_NAME.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, dataOfOneRecipientSeparatedByVerticalBars)) {
            if(LOGGED_USER_ID == getUserIdFromDataSeparatedByVerticalBars(dataOfOneRecipientSeparatedByVerticalBars)) {
                recipient = getRecipientDataFromLineToConstructor(dataOfOneRecipientSeparatedByVerticalBars);
                recipients.push_back(recipient);
            }
        }
        dataOfLastRecipientInFile = dataOfOneRecipientSeparatedByVerticalBars;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    if (dataOfLastRecipientInFile != "") {
        lastRecipientId = getRecipientIdFromDataSeparatedByVerticalBars(dataOfLastRecipientInFile);
    } else
        lastRecipientId = 0;

    return recipients;
}

int FileWithRecipients::getUserIdFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparatedByVerticalBars) {

    int userIdCharacterPosition = dataOfOneRecipientSeparatedByVerticalBars.find_first_of('|') + 1;
    int userId = AuxiliaryMethods::stringToIntConversion(AuxiliaryMethods::getNumber(dataOfOneRecipientSeparatedByVerticalBars, userIdCharacterPosition));

    return userId;
}

int FileWithRecipients::getRecipientIdFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparatedByVerticalBars) {

    int recipientIdCharacterPosition = 0;
    int recipientId = AuxiliaryMethods::stringToIntConversion(AuxiliaryMethods::getNumber(dataOfOneRecipientSeparatedByVerticalBars, recipientIdCharacterPosition));

    return recipientId;
}

Recipient FileWithRecipients::getRecipientDataFromLineToConstructor(string dataOfRecipientSeparatedByVerticalBars) {

    Recipient recipient;
    string paftOfRecipientData = "";
    int numberOfPartRecipientData = 1;

    for (int charPosition = 0; charPosition < dataOfRecipientSeparatedByVerticalBars.length(); charPosition++) {
        if (dataOfRecipientSeparatedByVerticalBars[charPosition] != '|') {
            paftOfRecipientData += dataOfRecipientSeparatedByVerticalBars[charPosition];
        } else {
            switch(numberOfPartRecipientData) {
            case 1:
                recipient.setRecipientId(atoi(paftOfRecipientData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(paftOfRecipientData.c_str()));
                break;
            case 3:
                recipient.setName(paftOfRecipientData);
                break;
            case 4:
                recipient.setSurname(paftOfRecipientData);
                break;
            case 5:
                recipient.setTelephone(paftOfRecipientData);
                break;
            case 6:
                recipient.setEmail(paftOfRecipientData);
                break;
            case 7:
                recipient.setAddress(paftOfRecipientData);
                break;
            }
            paftOfRecipientData = "";
            numberOfPartRecipientData++;
        }
    }
    return recipient;
}

void FileWithRecipients::addRecipientToFile(Recipient recipient) {

    string lineWithRecipientData = "";
    fstream textFile;

    textFile.open(FILE_NAME.c_str(), ios::out | ios::app);
    if (textFile.good() == true) {
        lineWithRecipientData = replaceRecipientDataForStringSeparatedByVerticalBars(recipient);

        if (isEmpty(textFile) == true) {
            textFile << lineWithRecipientData;
        } else {
            textFile << endl << lineWithRecipientData ;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    lastRecipientId++;
    textFile.close();
    system("pause");
}

string FileWithRecipients::replaceRecipientDataForStringSeparatedByVerticalBars(Recipient recipient) {

    string lineWithRecipientData = "";

    lineWithRecipientData += AuxiliaryMethods::intToStringConversion(recipient.getRecipientId()) + '|';
    lineWithRecipientData += AuxiliaryMethods::intToStringConversion(recipient.getUserId()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getSurname() + '|';
    lineWithRecipientData += recipient.getTelephone() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAddress() + '|';

    return lineWithRecipientData;
}

