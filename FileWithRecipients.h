#ifndef FILE_WITH_RECIPIENTS_H
#define FILE_WITH_RECIPIENTS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Recipient.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;


class FileWithRecipients:private TextFile {

    int lastRecipientId;

    string replaceRecipientDataForStringSeparatedByVerticalBars(Recipient recipient);
    int getUserIdFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparatedByVerticalBars);
    int getRecipientIdFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparatedByVerticalBars);
    Recipient getRecipientDataFromLineToConstructor(string dataOfRecipientSeparatedByVerticalBars);
    int getRecipientIdFromLine(string loadedLine);

public:

    FileWithRecipients(string fileNameWithRecipients)
        : TextFile(fileNameWithRecipients) {
        lastRecipientId = 0;
    };

    void addRecipientToFile(Recipient recipient);
    int setLastRecipientId();
    int getLastRecipientId();
    vector<Recipient> loadRecipientsOfLoggedUserFromFile(int LOGGED_USER_ID);
    void deleteRecipientInFile(int deleteRecipientId);
    void updateSelectedRecipientsDataInFile(Recipient recipient);
};


#endif
