//
// Created by frenk on 28/08/18.
//

#ifndef LABORATORIO_INIFILEMANAGER_H
#define LABORATORIO_INIFILEMANAGER_H

#include <string>
#include <map>

using namespace std;

class iniFileManager {
public:
    iniFileManager(string fileName);

    void setFileName(string fileName);
    string getFileName();
    string getValue (string section, string parameter);

    void setStringValue (string section, string parameter, string newValue);
    void setIntValue (string section, string parameter, int newValue);
    void setFloatValue (string section, string parameter, float newValue);
    void setBoolValue(string section, string parameter, bool newValue);

    bool removeSection(string section);
    bool removeParameter(string section, string parameter);

    void addSection (string sectionName);
    void addParameter(string section, string parameterName);

    void printSections();
    void printParameters(string section);
    void printValue(string section, string parameter);
    void printAll();

    void putToNull(string section, string parameter);

    virtual ~iniFileManager();


private:
    string fileName;
    map<string,map<string,string>> file;
};


#endif //LABORATORIO_INIFILEMANAGER_H
