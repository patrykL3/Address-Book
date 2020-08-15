#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <iostream>

using namespace std;


class Recipient {

    int recipientId;
    int userId;
    string name;
    string surname;
    string telephone;
    string email;
    string address;

public:

    Recipient(int id = 0, int userId = 0, string name = "", string surname = "", string telephone = "", string email = "", string address = "") {

        this -> recipientId = recipientId;
        this -> userId = userId;
        this -> name = name;
        this -> surname = surname;
        this -> telephone = telephone;
        this -> email = email;
        this -> address = address;
    }

    void setRecipientId(int newRecipientId);
    void setUserId(int newUserId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setTelephone(string newTelephone);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int getRecipientId();
    int getUserId();
    string getName();
    string getSurname();
    string getTelephone();
    string getEmail();
    string getAddress();
};


#endif
