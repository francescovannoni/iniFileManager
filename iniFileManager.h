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

    string getStringElement (string section, string parameter);
    int getIntElement (string section, string parameter);
    float getFloatElement (string section, string parameter);
    bool getBool (string section, string parameter);

    void setStringValue (string section, string parameter, string newValue);
    void setIntValue (string section, string parameter, int newValue);
    void setFloatValue (string section, string parameter, float newValue);
    void setBoolValue(string section, string parameter, bool newValue);

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
    map<string,map<string,string>> file;
};


#endif //LABORATORIO_INIFILEMANAGER_H
