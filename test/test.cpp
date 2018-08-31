//
// Created by frenk on 30/08/18.
//
#include "/home/frenk/CLionProjects/laboratorio/iniFileManager.cpp"
#include "/home/frenk/CLionProjects/laboratorio/iniFileManager.h"
#include "/home/frenk/CLionProjects/laboratorio/test/lib/googletest/include/gtest/gtest.h"

//constructor tester
TEST(iniFileManagerTest, ConstructorTest) {
    iniFileManager constructorTester("iniFile.ini");
    ASSERT_EQ(constructorTester.getFileName(), "iniFile.ini");
}

//getters, setters tests
TEST(iniFileManagerTest, StringGetterSetterTest) {
    iniFileManager file("Prova.ini");//
// Created by frenk on 28/08/18.
//

#include <iostream>
#include "iniFileManager.h"

using namespace std;


iniFileManager::iniFileManager(string filenName) {
    this->fileName = filenName;
    this->newProject.open(fileName);
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
    bool found = false;
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        std::cout << "ATTENZIONE: più valori inseriti per il parametro " << parameter
                  << " premere s per continuare e inserire l'ultimo valore immesso " << std::endl;
        string substitute;
        std::cin >> substitute;
        if (substitute == "s")
            file[section][parameter] = newValue;
    } else
        file[section][parameter] = newValue;
}

void iniFileManager::setIntValue(string section, string parameter, int newValue) {
    bool found = false;
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        std::cout << "ATTENZIONE: più valori inseriti per il parametro " << parameter
                  << " premere s per continuare e inserire l'ultimo valore immesso " << std::endl;
        string substitute;
        std::cin >> substitute;
        if (substitute == "s")
            file[section][parameter] = to_string(newValue);
    } else
        file[section][parameter] = to_string(newValue);

}

void iniFileManager::setFloatValue(string section, string parameter, float newValue) {
    bool found = false;
    for (auto &it : file[section]) {
        if (it.first == parameter) {
            found = true;
        }
    }
    if (found) {
        std::cout << "ATTENZIONE: più valori inseriti per il parametro " << parameter
                  << " premere s per continuare e inserire l'ultimo valore immesso " << std::endl;
        string substitute;
        std::cin >> substitute;
        if (substitute == "s")
            file[section][parameter] = to_string(newValue);
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

bool iniFileManager::removeSection(string section) {
    bool found = false;
    for (auto &it: file) {
        if (it.first == section)
            found = true;
    }
    if (found) {
        file.erase(section);
        return true;
    } else
        return false;
}

bool iniFileManager::removeParameter(string section, string parameter) {
    bool found = false;
    for (auto &it: file[section]) {
        if (it.first == parameter)
            found = true;
    }
    if (found) {
        file[section].erase(parameter);
        return true;
    } else
        return false;
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
        std::cout << "[" << it.first << "]" << std::endl;
        for (auto &secondIterator : file[it.first])
            std::cout << secondIterator.first << " = " << secondIterator.second << std::endl;
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


void iniFileManager::end() {
    this->newProject.close();

}

void iniFileManager::checkIsOpen() throw (std::runtime_error) {
    if (!newProject.is_open())
        throw std::runtime_error("file doesn't exist");
}


    file.setStringValue("Sezione 1", "Parametro 1", "valore 1");
    ASSERT_EQ(file.getValue("Sezione 1", "Parametro 1"), "valore 1");
}

TEST(iniFileManagerTest, IntGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setIntValue("Sezione 1", "Parametro 2", 5);
    ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(iniFileManagerTest, FloatGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setFloatValue("Sezione 2", "Parametro 1", 5.98);
    ASSERT_EQ(stof(file.getValue("Sezione 2", "Parametro 1")), 5.98);
}


TEST(iniFileManagerTest, BoolGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setBoolValue("Sezione 3", "Parametro 1", false);
    ASSERT_EQ(file.getValue("Sezione 3", "Parametro 1"), "false");
}

//add and remove section and parameter
TEST(iniFileManagerTest, SectionsTest) {
    iniFileManager file("Prova.ini");
    file.addSection("Sezione prova rimozione");
    ASSERT_EQ(file.removeSection("Sezione prova rimozione"), true);
}

TEST(iniFileManagerTest, ParameterTest) {
    iniFileManager file("Prova.ini");
    file.addParameter("Sezione", "Parametro");
    ASSERT_EQ(file.removeParameter("Sezione", "Parametro"), true);
}


TEST(iniFileManagerTest, PutToNullTest) {
    iniFileManager file("Prova.ini");
    file.putToNull("Sezione 4", "Parametro 6");
    ASSERT_EQ(file.getValue("Sezione 4", "Parametro 6"), "null");
}

TEST(iniFileManagerTest, NumParametersTest) {
    iniFileManager file("Prova.ini");
    file.setStringValue("Sezione 4", "Parametro 6", "Valore stringa");
    file.setIntValue("Sezione 4", "Parametro 8", 5);
    ASSERT_EQ(file.numParameters("Sezione 4"), 2);
}

TEST(iniFileManagerTest, IsOpenException) {
    iniFileManager file("Prova.ini");
    file.end();
    EXPECT_THROW(file.checkIsOpen(), std::runtime_error);

}









