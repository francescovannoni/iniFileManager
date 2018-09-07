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
    iniFileManager(string fileName, int maxNumOfComments = 100);

    void setFileName(string fileName);

    string getFileName();

    string getValue(string section, string parameter);

    void setStringValue(string section, string parameter, string newValue);

    void setIntValue(string section, string parameter, int newValue);

    void setFloatValue(string section, string parameter, float newValue);

    void setBoolValue(string section, string parameter, bool newValue);

    void removeSection(string section);

    void removeParameter(string section, string parameter);

    void addSection(string sectionName);

    void addParameter(string section, string parameterName);

    bool findSection(string section);

    bool findParameter(string section, string parameter);

    void printSections();

    void printParameters(string section);

    void printValue(string section, string parameter);

    void printAll();

    void end();

    void checkIsOpen() throw(std::runtime_error);

    void reset();

    void putToNull(string section, string parameter);

    int numParameters(string section);

    virtual ~iniFileManager();

    void addComment(string section, string commentText, bool inSection = false);

    void modify(string section, string parameter, string newValue);

private:
    string fileName;
    map<string, map<string, string>> file;
    int currentComment;
    int maxNumOfComment;
    fstream newProject;
};


#endif //LABORATORIO_INIFILEMANAGER_H
