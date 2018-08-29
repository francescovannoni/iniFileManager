//
// Created by frenk on 28/08/18.
//

#include "iniFileManager.h"
using namespace std;

iniFileManager::iniFileManager(string filenName) {
this->fileName = filenName;
}

iniFileManager::~iniFileManager() {

}

string iniFileManager::getStringElement(string section, string parameter) {
    return std::__cxx11::string();
}

int iniFileManager::getIntElement(string section, string parameter) {
    return 0;
}

float iniFileManager::getFloatElement(string section, string parameter) {
    return 0;
}

bool iniFileManager::getBool(string section, string parameter) {
    return false;
}

void iniFileManager::setStringElement(string section, string parameter, string newElement) {

}

void iniFileManager::setIntElement(string section, string parameter, int newElement) {

}

void iniFileManager::setFloatElement(string section, string parameter, float newElement) {

}

void iniFileManager::setBoolElement(string section, string parameter, bool newElement) {

}



