#include <iostream>
#include "arreglos.h"
#include "registros.h"
#include "archivos.h"
using namespace std;

int main() {
    int opcion;

    do {
        cout << "\n=========== MENU PRINCIPAL ===========\n";
        cout << "1. Arreglos Unidimensionales\n";
        cout << "2. Registros\n";
        cout << "3. Archivos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no valida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: menuArreglos(); break;
            case 2: menuRegistros(); break;
            case 3: menuArchivos(); break;
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 4);

    return 0;
}
