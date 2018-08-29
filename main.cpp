#include <iostream>
#include "iniFileManager.h"

int main() {
    iniFileManager antonio("ciao");
    antonio.setFloatValue("Nome", "Primo Numero", 5.7);
    antonio.setFloatValue("Nome", "Terzo Numero", 5.9);
    antonio.setFloatValue("Nome", "Terzo Numero", 7.8);

    antonio.setIntValue("Cognome", "Numero Intero", 56);

    antonio.printAll();

}