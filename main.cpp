#include <iostream>

#include "AddressBook.h"

using namespace std;


int main() {
    AddressBook addressBook("Users.txt", "Recipients.txt");
    char choice;

    while (true) {
        if (!addressBook.isLogged()) {
            choice = addressBook.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                addressBook.userRegistration();
                break;
            case '2':
                addressBook.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = addressBook.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                addressBook.addRecipient();
                break;
            case '2':
                addressBook.searchRecipientByName();
                break;
            case '3':
                addressBook.searchRecipientBySurname();
                break;
            case '4':
                addressBook.displayAllRecipients();
                break;
            case '5':
                addressBook.deleteRecipient();
                break;
            case '6':
                addressBook.editRecipient();
                break;
            case '7':
                addressBook.changePasswordLoggedUser();
                break;
            case '8':
                addressBook.logOutUser();
                break;
            }
        }
    }
    return 0;
}

