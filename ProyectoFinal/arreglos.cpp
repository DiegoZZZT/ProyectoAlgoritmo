#include <iostream>
#include <limits>
using namespace std;

void menuArreglos() {
    int n;
    cout << "\n=== ARREGLOS UNIDIMENSIONALES ===\n";

    do {
        cout << "Ingrese el tamano del arreglo (mayor a 0): ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor invalido. Ingrese un numero entero positivo.\n";
            n = 0;
        }
    } while (n <= 0);

    float* arreglo = new float[n];
    float* cubos = new float[n];

    cout << "\n--- Ingreso de datos tipo real ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        while (!(cin >> arreglo[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero real: ";
        }
    }

    for (int i = 0; i < n; i++) {
        cubos[i] = arreglo[i] * arreglo[i] * arreglo[i];
    }

    cout << "\n--- Resultado (cubo de cada elemento) ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Posicion [" << i << "]: " << cubos[i] << endl;
    }

    delete[] arreglo;
    delete[] cubos;
}
