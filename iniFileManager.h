//
// Created by frenk on 28/08/18.
//

#ifndef LABORATORIO_INIFILEMANAGER_H
#define LABORATORIO_INIFILEMANAGER_H

#include <string>
#include <map>
#include <fstream>

using namespace std;

class iniFileManager {
public:
    explicit iniFileManager(string fileName);

    void setFileName(string fileName);

    string getFileName();

    string getValue(string section, string parameter);

    void setStringValue(string section, string parameter, string newValue);

    void setIntValue(string section, string parameter, int newValue);

    void setFloatValue(string section, string parameter, float newValue);

    void setBoolValue(string section, string parameter, bool newValue);

    bool removeSection(string section);

    bool removeParameter(string section, string parameter);

    void addSection(string sectionName);

    void addParameter(string section, string parameterName);

    void printSections();

    void printParameters(string section);

    void printValue(string section, string parameter);

    void printAll();

    void reset();

    void putToNull(string section, string parameter);

    int numParameters(string section);

    virtual ~iniFileManager();

    void end();

    void checkIsOpen() throw(std::runtime_error);

private:
    string fileName;
    fstream newProject;
    map<string, map<string, string>> file;
};


#endif //LABORATORIO_INIFILEMANAGER_H
