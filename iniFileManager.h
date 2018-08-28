//
// Created by frenk on 28/08/18.
//

#ifndef LABORATORIO_INIFILEMANAGER_H
#define LABORATORIO_INIFILEMANAGER_H

#include <string>

using namespace std;
class iniFileManager {
public:
    iniFileManager(string fileName);
    string getStringElement (string section, string keyName);
    int getIntElement (string section, string keyName);
    float getFloatElement (string section, string keyName);

    void setStringElement (string section, string keyName, string newElement);
    void setFloatElement (string section, string keyName, float newElement);
    void setBoolElement (string section, string keyName, bool  newElement);




    virtual ~iniFileManager();


private:
    string fileName;
};


#endif //LABORATORIO_INIFILEMANAGER_H
