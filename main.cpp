#include <iostream>
#include "iniFileManager.h"
using namespace std;

int main() {
    iniFileManager file("FirstProgram.ini");
    std::cout << "File Name: " << file.getFileName() << std::endl;

    file.setIntValue("Sezione 1", "Parametro 1", 14);
    file.setFloatValue("Sezione 2", "Parametro 1", 3.14);
    file.setBoolValue("Sezione 1", "Parametro 2", false);
    file.setStringValue("Sezione 1", "Parametro 2", "Valore 1");

    file.addSection("Sezione 3");
    file.addParameter("Sezione 2", "Parametro 3");
    file.putToNull("Sezione 2", "Parametro 1");

    file.printAll();

    int numberOfParameters = file.numParameters("Sezione 3");
    std::cout << "Numero parametri della terza sezione: " << numberOfParameters << std::endl;


    file.close();
}
