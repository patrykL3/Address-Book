#ifndef RECIPIENT_MANAGER_H
#define RECIPIENT_MANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FileWithRecipients.h"
#include "Recipient.h"
#include "AuxiliaryMethods.h"

using namespace std;


class RecipientManager {

    const int LOGGED_USER_ID;
    vector<Recipient> recipients;
    FileWithRecipients fileWithRecipients;

    void displayRecipientData(Recipient recipient);
    Recipient enterNewRecipientData();
    string replaceFirstLetterToLargeAndOthersToSmall(string text);
    void displayCountSearchedRecipients(int recipientCount);
    int enterIdSelectedRecipient();
    char selectOptionFromEditMenu();

public:

    RecipientManager(string fileNameWithRecipients, int loggedUserId)
        : fileWithRecipients(fileNameWithRecipients), LOGGED_USER_ID (loggedUserId) {
        recipients = fileWithRecipients.loadRecipientsOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void searchRecipientByName();
    void searchRecipientBySurname();
    void addRecipient();
    void deleteRecipient();
    void editRecipient();
    void displayAllRecipients();
};


#endif
