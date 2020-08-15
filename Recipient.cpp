#include"Recipient.h"


void Recipient::setRecipientId(int newRecipientId) {
    recipientId = newRecipientId;
}

void Recipient::setUserId(int newUserId) {
    userId = newUserId;
}

void Recipient::setName(string newName) {
    name = newName;
}

void Recipient::setSurname(string newSurname) {
    surname = newSurname;
}

void Recipient::setTelephone(string newTelephone) {
    telephone = newTelephone;
}

void Recipient::setEmail(string newEmail) {
    email = newEmail;
}

void Recipient::setAddress(string newAddress) {
    address = newAddress;
}


int Recipient::getRecipientId() {
    return recipientId;
}

int Recipient::getUserId() {
    return userId;
}
string Recipient::getName() {
    return name;
}

string Recipient::getSurname() {
    return surname;
}

string Recipient::getTelephone() {
    return telephone;
}

string Recipient::getEmail() {
    return email;
}

string Recipient::getAddress() {
    return address;
}

