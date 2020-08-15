#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;


class User {

    int id;
    string login;
    string password;

public:

    User(int id = 0, string login = "", string password = "") {
        this -> id = id;
        this -> login = login;
        this -> password = password;
    }

    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getLogin();
    string getPassword();
};


#endif
