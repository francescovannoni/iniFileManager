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

    virtual ~iniFileManager();


private:
    string fileName;
};


#endif //LABORATORIO_INIFILEMANAGER_H
