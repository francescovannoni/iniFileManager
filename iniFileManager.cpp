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
}

float iniFileManager::getFloatElement(string section, string parameter) {
    return 0;
}

bool iniFileManager::getBool(string section, string parameter) {
    return false;
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

bool iniFileManager::addSection(string sectionName) {
    return false;
}

string iniFileManager::getSections() {
    return std::__cxx11::string();
}

bool iniFileManager::addParameter(string parameterName) {
    return false;
}

void iniFileManager::getParameter() {

}

bool iniFileManager::deleteInt(string section, string parameter, int valueDeleted) {
    return false;
}

bool iniFileManager::deleteString(string section, string parameter, string valueDeleted) {
    return false;
}

bool iniFileManager::deleteBool(string section, string parameter, bool valueDeleted) {
    return false;
}

bool iniFileManager::deleteFloat(string section, string parameter, float valueDeleted) {
    return false;
}




