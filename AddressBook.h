#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <iostream>
#include"AuxiliaryMethods.h"
#include"UserManager.h"
#include "RecipientManager.h"

using namespace std;


class AddressBook {

    UserManager userManager;
    RecipientManager *recipientManager;
    const string FILE_NAME_WITH_RECIPIENTS;

public:

    AddressBook(string fileNameWithUsers, string fileNameWithRecipients)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_RECIPIENTS(fileNameWithRecipients) {
        recipientManager = NULL;
    };
    ~AddressBook() {
        delete recipientManager;
        recipientManager = NULL;
    }

    bool isLogged();
    char selectOptionFromMainMenu();
    void userRegistration();
    void userLogin();

    char selectOptionFromUserMenu();
    void addRecipient();
    void searchRecipientByName();
    void searchRecipientBySurname();
    void displayAllRecipients();
    void deleteRecipient();
    void editRecipient();
    void changePasswordLoggedUser();
    void logOutUser();
};


#endif

