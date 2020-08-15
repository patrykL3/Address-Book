#include "RecipientManager.h"


void RecipientManager::editRecipient() {

    int editRecipientId = 0;
    char choice;
    bool recipientExists = false;
    Recipient recipient;

    system("cls");
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    editRecipientId = enterIdSelectedRecipient();

    for (int i = 0; i < recipients.size(); i++) {
        if (recipients[i].getRecipientId() == editRecipientId) {
            recipientExists = true;
            choice = selectOptionFromEditMenu();

            switch (choice) {
            case '1':
                cout << "Podaj nowe imie: ";
                recipients[i].setName(replaceFirstLetterToLargeAndOthersToSmall(AuxiliaryMethods::loadLine()));
                fileWithRecipients.updateSelectedRecipientsDataInFile(recipients[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                recipients[i].setSurname(replaceFirstLetterToLargeAndOthersToSmall(AuxiliaryMethods::loadLine()));
                fileWithRecipients.updateSelectedRecipientsDataInFile(recipients[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                recipients[i].setTelephone(AuxiliaryMethods::loadLine());
                fileWithRecipients.updateSelectedRecipientsDataInFile(recipients[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                recipients[i].setEmail(AuxiliaryMethods::loadLine());
                fileWithRecipients.updateSelectedRecipientsDataInFile(recipients[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                recipients[i].setAddress(AuxiliaryMethods::loadLine());
                fileWithRecipients.updateSelectedRecipientsDataInFile(recipients[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (recipientExists == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char RecipientManager::selectOptionFromEditMenu() {

    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void RecipientManager::deleteRecipient() {

    int deleteRecipientId = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    deleteRecipientId = enterIdSelectedRecipient();

    char confirmationCharacter;
    bool recipientExists = false;

    for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++) {
        if (itr -> getRecipientId() == deleteRecipientId) {
            recipientExists = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            confirmationCharacter = AuxiliaryMethods::loadChar();
            if (confirmationCharacter == 't') {
                fileWithRecipients.deleteRecipientInFile(deleteRecipientId);
                recipients.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                break;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (recipientExists == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}


int RecipientManager::enterIdSelectedRecipient() {

    int selectedRecipientId = 0;

    cout << "Podaj numer ID Adresata: ";
    selectedRecipientId  = AuxiliaryMethods::loadInteger();
    return selectedRecipientId;
}

void RecipientManager::searchRecipientBySurname() {

    string surnameOfTheRecipientSearched;
    int recipientCount = 0;

    system("cls");
    if (!recipients.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        surnameOfTheRecipientSearched = AuxiliaryMethods::loadLine();
        surnameOfTheRecipientSearched = replaceFirstLetterToLargeAndOthersToSmall(surnameOfTheRecipientSearched);

        for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++) {
            if (itr -> getSurname() == surnameOfTheRecipientSearched) {
                displayRecipientData(*itr);
                recipientCount++;
            }
        }
        displayCountSearchedRecipients(recipientCount);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::searchRecipientByName() {

    string nameOfTheRecipientSearched = "";
    int recipientCount = 0;

    system("cls");
    if (!recipients.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nameOfTheRecipientSearched = AuxiliaryMethods::loadLine();
        nameOfTheRecipientSearched = replaceFirstLetterToLargeAndOthersToSmall(nameOfTheRecipientSearched);

        for (vector <Recipient>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++) {
            if (itr -> getName() == nameOfTheRecipientSearched) {
                displayRecipientData(*itr);
                recipientCount++;
            }
        }
        displayCountSearchedRecipients(recipientCount);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::displayCountSearchedRecipients(int recipientCount) {

    if (recipientCount == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << recipientCount << endl << endl;
}


string RecipientManager::replaceFirstLetterToLargeAndOthersToSmall(string text) {

    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

Recipient RecipientManager::enterNewRecipientData() {

    Recipient recipient;

    recipient.setRecipientId(fileWithRecipients.getLastRecipientId() + 1);
    recipient.setUserId(LOGGED_USER_ID);

    cout << "Podaj imie: ";
    recipient.setName(replaceFirstLetterToLargeAndOthersToSmall(AuxiliaryMethods::loadLine()));

    cout << "Podaj nazwisko: ";
    recipient.setSurname(replaceFirstLetterToLargeAndOthersToSmall(AuxiliaryMethods::loadLine()));

    cout << "Podaj numer telefonu: ";
    recipient.setTelephone(AuxiliaryMethods::loadLine());

    cout << "Podaj email: ";
    recipient.setEmail(AuxiliaryMethods::loadLine());

    cout << "Podaj adres: ";
    recipient.setAddress(AuxiliaryMethods::loadLine());

    return recipient;
}

void RecipientManager::addRecipient() {

    Recipient recipient;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    recipient = enterNewRecipientData();
    recipients.push_back(recipient);
    fileWithRecipients.addRecipientToFile(recipient);
}

void RecipientManager::displayAllRecipients() {

    system("cls");
    if (!recipients.empty()) {
        cout << "             >>> Adresaci <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Recipient> :: iterator itr = recipients.begin(); itr != recipients.end(); itr++) {
            displayRecipientData(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void RecipientManager::displayRecipientData(Recipient recipient) {

    cout << endl << "Id:                 " << recipient.getRecipientId() << endl;
    cout << "Imie:               " << recipient.getName() << endl;
    cout << "Nazwisko:           " << recipient.getSurname() << endl;
    cout << "Numer telefonu:     " << recipient.getTelephone() << endl;
    cout << "Email:              " << recipient.getEmail() << endl;
    cout << "Adres:              " << recipient.getAddress() << endl;
}

