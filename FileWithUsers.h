#ifndef FILE_WITH_USERS_H
#define FILE_WITH_USERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;


class FileWithUsers:private TextFile {

    string replaceUserDataForStringSeparatedByVerticalBars(User user);
    User getUserData(string oneUserDataSeparatedByVerticalBars);

public:

    FileWithUsers(string fileNameWithUsers) : TextFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    void addAllUsersToFile(vector <User> users);
    vector<User> loadUsersFromFile();
};


#endif
