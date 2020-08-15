#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <iostream>
#include <fstream>

using namespace std;


class TextFile {

protected:

    const string FILE_NAME;

    bool isEmpty(fstream &plikTekstowy);
    void deleteFile(string fileName);
    void changeFileName(string oldName, string newName);

    TextFile(string fileName) : FILE_NAME(fileName) {}
};


#endif
