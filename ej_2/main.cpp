#include <iostream>
#include "Curso.hpp"

using namespace std;

int main() {

    while(true) {
        cout << "Indique el número de la opción que desea realizar \n Escriba exit si desea salir.";        
        string input;
        cin >> input;
        if (input == "exit") break;
        cout << "1. \n";
        cout << "2. \n";
        cout << "3. \n";
        cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
        cout << "7. \n";
        cout << "8. \n";
    }


    return 0;
}