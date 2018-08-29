//
// Created by frenk on 28/08/18.
//

#ifndef LABORATORIO_INIFILEMANAGER_H
#define LABORATORIO_INIFILEMANAGER_H

#include <string>
#include <map>

using namespace std;
template <typename T>
class iniFileManager {
public:
    iniFileManager(string fileName);

    T& getValues (string section, string parameter);

    void addValues (string section, string parameter, T newValue);

    bool addSection (string sectionName);
    string getSections();

    bool addParameter(string parameterName);
    void getParameter();

    bool deleteInt(string section, string parameter, int valueDeleted);
    bool deleteString(string section, string parameter, string valueDeleted);
    bool deleteBool(string section, string parameter, bool valueDeleted);
    bool deleteFloat(string section, string parameter, float valueDeleted);

    virtual ~iniFileManager();


private:
    string fileName;
    map<string,map<string,T>> file;
};


#endif //LABORATORIO_INIFILEMANAGER_H
