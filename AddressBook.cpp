#include "AddressBook.h"


void AddressBook::editRecipient() {

    recipientManager -> editRecipient();
}

void AddressBook::deleteRecipient() {

    recipientManager -> deleteRecipient();
}

void AddressBook::searchRecipientBySurname() {

    recipientManager -> searchRecipientBySurname();
}

void AddressBook::searchRecipientByName() {

    recipientManager -> searchRecipientByName();
}

void AddressBook::logOutUser() {

    userManager.logOutUser();
    delete recipientManager;
    recipientManager = NULL;
}

void AddressBook::changePasswordLoggedUser() {

    userManager.changePasswordLoggedUser();
}

void AddressBook::displayAllRecipients() {

    recipientManager -> displayAllRecipients();
}

char AddressBook::selectOptionFromUserMenu() {

    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void AddressBook::addRecipient() {

    recipientManager -> addRecipient();
}

void AddressBook::userRegistration() {

    userManager.userRegistration();
}

void AddressBook::userLogin() {

    userManager.userLogin();
    if (userManager.isLogged())
        recipientManager = new RecipientManager(FILE_NAME_WITH_RECIPIENTS, userManager.getIdLoggedUser());
}

bool AddressBook::isLogged() {

    return (userManager.getIdLoggedUser() == 0) ? false : true;
}


char AddressBook::selectOptionFromMainMenu() {

    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

