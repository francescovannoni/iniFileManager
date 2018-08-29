//
// Created by frenk on 28/08/18.
//

#include "iniFileManager.h"
using namespace std;


iniFileManager ::iniFileManager(string filenName) {
this->fileName = filenName;
}

iniFileManager::~iniFileManager() {

}

string iniFileManager::getStringElement(string section, string parameter) {
    return std::__cxx11::string();
}

int iniFileManager::getIntElement(string section, string parameter) {
    return stoi(file[section][parameter]);
}

float iniFileManager::getFloatElement(string section, string parameter) {
    return stof(file[section][parameter]);
}

bool iniFileManager::getBool(string section, string parameter) {
    if (file[section][parameter] == "true")
        return "true";
    else
        return "false";
}

void iniFileManager::setStringValue(string section, string parameter, string newValue) {
file[section][parameter] = newValue;
}

void iniFileManager::setIntValue(string section, string parameter, int newValue) {
    file[section][parameter] = to_string(newValue);
}

void iniFileManager::setFloatValue(string section, string parameter, float newValue) {
    file[section][parameter] = to_string(newValue);
}

void iniFileManager::setBoolValue(string section, string parameter, bool newValue) {
    if (newValue)
        file[section][parameter] = "true";
    else
        file[section][parameter] = "false";
}

void iniFileManager::addSection(string sectionName) {
    file[sectionName];
}


void iniFileManager::addParameter(string section, string parameterName) {
    file[section][parameterName] = "null";
}


void iniFileManager::putToNull(string section, string parameter) {
    file[section][parameter] = "null";
}

bool iniFileManager::removeSection(string section) {
    bool found = false;
    for (auto & it: file) {
        if (it.first == section)
            found = true;
    }
    if (found){
        file.erase(section);
    return true;
    }
    else
        return false;
}

bool iniFileManager::removeParameter(string section, string parameter) {
    bool found = false;
    for (auto & it: file[section]) {
        if (it.first == parameter)
            found = true;
    }
    if (found){
        file[section].erase(parameter);
        return true;
    }
    else
        return false;
}
}






