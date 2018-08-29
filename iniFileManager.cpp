//
// Created by frenk on 28/08/18.
//

#include <iostream>
#include "iniFileManager.h"
using namespace std;


iniFileManager ::iniFileManager(string filenName) {
this->fileName = filenName;
}

iniFileManager::~iniFileManager() {

}

void iniFileManager::setFileName(string fileName) {
    this->fileName = fileName;
}

string iniFileManager::getFileName() {
    return this->fileName;
}

string iniFileManager::getValue(string section, string parameter) {
    return file[section][parameter];
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

void iniFileManager::printSections() {
    std::cout << "Sections:" << std::endl;
    for (auto &it:file)
        std::cout << it.first << std::endl;
}

void iniFileManager::printParameters(string section) {
    std::cout << "Parameters:" << std::endl;
    for (auto &it:file[section])
        std::cout << it.first << std::endl;
}

void iniFileManager::printValue(string section, string parameter) {
    std::cout << parameter << "=" << file[section][parameter] << std::endl;
}

void iniFileManager::printAll() {
    for (auto &it:file) {
        std::cout << "[" <<it.first << "]" << std::endl;
        for (auto &secondIterator : file[it.first])
            std::cout << secondIterator.first << "=" << secondIterator.second << std::endl;
    }
}








//add comment


