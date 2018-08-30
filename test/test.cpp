//
// Created by frenk on 30/08/18.
//
#include "/home/frenk/CLionProjects/laboratorio/iniFileManager.cpp"
#include "/home/frenk/CLionProjects/laboratorio/iniFileManager.h"
#include "/home/frenk/CLionProjects/laboratorio/test/lib/googletest/include/gtest/gtest.h"

//constructor tester
TEST(iniFileManagerTest, ConstructorTest){
    iniFileManager constructorTester("iniFile.ini");
    ASSERT_EQ(constructorTester.getFileName(), "iniFile.ini");
}

//getters, setters tests
TEST(iniFileManagerTest, StringGetterSetterTest) {
iniFileManager file("Prova.ini");
file.setStringValue("Sezione 1", "Parametro 1", "valore 1");
ASSERT_EQ(file.getValue("Sezione 1", "Parametro 1"), "Parametro 1");
}

TEST(iniFileManagerTest, IntGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setIntValue("Sezione 1", "Parametro 2", 5);
    ASSERT_EQ(stoi(file.getValue("Sezione 1", "Parametro 2")), 5);
}

TEST(iniFileManagerTest, FloatGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setFloatValue("Sezione 2", "Parametro 1", 5.9);
    ASSERT_EQ(stof(file.getValue("Sezione 2", "Parametro 1")), 5.9);
}

TEST(iniFileManagerTest, BoolGetterSetterTest) {
    iniFileManager file("Prova.ini");
    file.setBoolValue("Sezione 3", "Parametro 1", false);
    ASSERT_EQ(file.getValue("Sezione 3", "Parametro 1"), "false");
}










