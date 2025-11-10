#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

void menuArchivos() {
    string nombreArchivo, nuevaLinea;
    const string archivoSalida = "lineas_mayores20.txt";
    int opcion;

    do {
        cout << "\n=== ARCHIVOS ===\n";
        cout << "1. Lectura de archivo\n";
        cout << "2. Mostrar archivo con lineas mayores de 20 caracteres\n";
        cout << "3. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada no valida.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\nIngrese el nombre del archivo (con extension .txt): ";
                cin.ignore();
                getline(cin, nombreArchivo);

                ifstream archivoEntrada(nombreArchivo);
                ofstream archivoNuevo(archivoSalida);

                if (!archivoEntrada.is_open()) {
                    cout << "No se pudo abrir el archivo '" << nombreArchivo << "'.\n";
                    break;
                }

                cout << "\n--- Longitud de cada linea ---\n";
                int contador = 0;
                while (getline(archivoEntrada, nuevaLinea)) {
                    cout << "[" << ++contador << "] (" << nuevaLinea.length() << " caracteres): "
                         << nuevaLinea << endl;
                    if (nuevaLinea.length() > 20) {
                        archivoNuevo << nuevaLinea << endl;
                    }
                }

                archivoEntrada.close();
                archivoNuevo.close();
                cout << "\nLas lineas mayores de 20 caracteres se guardaron en '" << archivoSalida << "'.\n";
                break;
            }
            case 2: {
                ifstream archivoLectura(archivoSalida);
                if (!archivoLectura.is_open()) {
                    cout << "No existe el archivo '" << archivoSalida << "'. Ejecute primero la opcion 1.\n";
                    break;
                }

                cout << "\n--- Contenido de '" << archivoSalida << "' ---\n";
                int contador = 0;
                while (getline(archivoLectura, nuevaLinea)) {
                    cout << ++contador << ". " << nuevaLinea << endl;
                }
                archivoLectura.close();

                if (contador == 0)
                    cout << "(El archivo esta vacio, no hubo lineas mayores de 20 caracteres.)\n";
                break;
            }
            case 3:
                cout << "Regresando al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);
}
