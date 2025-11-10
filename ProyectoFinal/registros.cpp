#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct Producto {
    string nombre;
    string categoria;
    float precio;
};

void mostrarEncabezado() {
    cout << left << setw(5) << "No."
         << setw(25) << "Nombre"
         << setw(20) << "Categoria"
         << setw(10) << "Precio" << endl;
    cout << string(60, '-') << endl;
}

void mostrarProducto(const Producto& p, int indice) {
    cout << left << setw(5) << indice + 1
         << setw(25) << p.nombre
         << setw(20) << p.categoria
         << "$" << fixed << setprecision(2) << p.precio << endl;
}

void menuRegistros() {
    const int TAM = 25;
    Producto productos[TAM];
    int contador = 0;
    int opcion;

    do {
        cout << "\n=== REGISTROS DE PRODUCTOS ===\n";
        cout << "1. Ingreso de datos\n";
        cout << "2. Promedio de precios\n";
        cout << "3. Consulta de registros\n";
        cout << "4. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no valida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                int cantidad;
                cout << "\n--- Ingreso de datos de productos ---\n";
                do {
                    cout << "Cuantos productos desea ingresar (1 - " << TAM << "): ";
                    cin >> cantidad;
                    if (cin.fail() || cantidad <= 0 || cantidad > TAM) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Cantidad invalida. Ingrese un numero entre 1 y " << TAM << ".\n";
                        cantidad = 0;
                    }
                } while (cantidad <= 0 || cantidad > TAM);

                contador = cantidad;

                for (int i = 0; i < contador; i++) {
                    cout << "\nProducto #" << i + 1 << endl;
                    cin.ignore();
                    cout << "Nombre: ";
                    getline(cin, productos[i].nombre);
                    cout << "Categoria: ";
                    getline(cin, productos[i].categoria);

                    do {
                        cout << "Precio: ";
                        cin >> productos[i].precio;
                        if (cin.fail() || productos[i].precio < 0) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Ingrese un precio valido (no negativo).\n";
                            productos[i].precio = -1;
                        }
                    } while (productos[i].precio < 0);
                }

                cout << "\nDatos ingresados correctamente.\n";
                break;
            }
            case 2: {
                cout << "\n--- Promedio de precios ---\n";
                if (contador == 0) {
                    cout << "No hay productos ingresados.\n";
                    break;
                }
                float suma = 0;
                for (int i = 0; i < contador; i++) {
                    suma += productos[i].precio;
                }
                cout << fixed << setprecision(2);
                cout << "El promedio de precios es: $" << (suma / contador) << endl;
                break;
            }
            case 3: {
                cout << "\n--- Consulta de registros ---\n";
                if (contador == 0) {
                    cout << "No hay productos ingresados.\n";
                    break;
                }
                mostrarEncabezado();
                for (int i = 0; i < contador; i++) {
                    mostrarProducto(productos[i], i);
                }
                break;
            }
            case 4:
                cout << "Regresando al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);
}
