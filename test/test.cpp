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
    iniFileManager file("Prova.ini");
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
    ASSERT_TRUE(abs(stof(file.getValue("Sezione 2", "Parametro 1")) - 5.98)<0.0001);
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









