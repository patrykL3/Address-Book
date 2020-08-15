#include "TextFile.h"


void TextFile::deleteFile(string fileName) {

    if (remove(fileName.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileName << endl;
}

void TextFile::changeFileName(string oldName, string newName) {

    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << oldName << endl;
}


bool TextFile::isEmpty(fstream &textFile) {

    textFile.seekg(0, ios::end);
    return (textFile.tellg() == 0) ? true : false;
}
