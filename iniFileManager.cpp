//
// Created by frenk on 28/08/18.
//

#include <iostream>
#include "iniFileManager.h"

using namespace std;


iniFileManager::iniFileManager(string fileName, int maxNumOfComments) {
    this->fileName = fileName;
    this->newProject.open(fileName);
    this->maxNumOfComment = maxNumOfComments;
    this->currentComment = 0;
}

iniFileManager::~iniFileManager() {
    this->newProject.close();
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
    bool found = false;
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        modify(section, parameter, newValue);
    } else
        file[section][parameter] = newValue;
}

void iniFileManager::setIntValue(string section, string parameter, int newValue) {
    bool found = false;
    string value = to_string(newValue);
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        modify(section, parameter, value);
    } else
        file[section][parameter] = to_string(newValue);

}

void iniFileManager::setFloatValue(string section, string parameter, float newValue) {
    bool found = false;
    string value = to_string(newValue);
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        modify(section, parameter, value);
    } else
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

void iniFileManager::removeSection(string section) {
    bool found = false;
    for (auto &it: file) {
        if (it.first == section)
            found = true;
    }
    if (found) {
        file.erase(section);
    } else
        throw std::runtime_error("Section doesn't exist");
}

void iniFileManager::removeParameter(string section, string parameter) {
    bool found = false;
    for (auto &it: file[section]) {
        if (it.first == parameter)
            found = true;
    }
    if (found) {
        file[section].erase(parameter);
    } else {
        throw std::runtime_error("Parameter doesn't exist");
    }
}

void iniFileManager::printSections() {
    std::cout << "Sezioni:" << std::endl;
    for (auto &it:file)
        std::cout << it.first << std::endl;
}

void iniFileManager::printParameters(string section) {
    std::cout << "Parametri della sezione" << section << ":" << std::endl;
    for (auto &it:file[section])
        std::cout << it.first << std::endl;
}

void iniFileManager::printValue(string section, string parameter) {
    std::cout << parameter << "=" << file[section][parameter] << std::endl;
}

void iniFileManager::printAll() {
    for (auto &it:file) {
        if (it.first == "commenti")
            for (auto &secondIterator : file["commenti"])
                std::cout << secondIterator.second << std::endl;
        else {
            std::cout << "[" << it.first << "]" << std::endl;
            for (auto &secondIterator : file[it.first]) {
                int value = 0;
                bool commentFound = false;
                while (value < maxNumOfComment && !commentFound) {
                    if (secondIterator.first == to_string(value)) {
                        commentFound = true;
                        std::cout << secondIterator.second << std::endl;
                    } else
                        value++;
                }
                if (!commentFound)
                    std::cout << secondIterator.first << " = " << secondIterator.second << std::endl;

            }
        }
    }
}

void iniFileManager::reset() {
    std::cout << "Vuoi davvero eliminare tutto? [S/N] " << std::endl;
    string clear;
    cin >> clear;
    if (clear == "S")
        file.clear();
}

int iniFileManager::numParameters(string section) {
    int count = 0;
    for (auto &it: file[section])
        count++;
    std::cout << "" << std::endl;
    return count;
}


void iniFileManager::addComment(string section, string commentText, bool inSection) {
    string parameter;
    currentComment += 1;
    parameter = to_string(currentComment);
    if (inSection)
        file[section][parameter] = "; " + commentText;
    else
        file["commenti"][parameter] = "; " + commentText;
}

void iniFileManager::modify(string section, string parameter, string newValue) {
    std::cout << "ATTENZIONE: più valori inseriti per il parametro " << parameter
              << " premere s per continuare e inserire l'ultimo valore immesso " << std::endl;
    string substitute;
    std::cin >> substitute;
    if (substitute == "s")
        file[section][parameter] = newValue;
}

void iniFileManager::end() {
    this->newProject.close();
}

void iniFileManager::checkIsOpen() throw(std::runtime_error) {
    if (!newProject.is_open())
        throw std::runtime_error("file doesn't exist");

}





