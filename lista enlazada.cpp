#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    Nodo* inicio = NULL;
    Nodo* fin = NULL;

    char opcion;
    int valor;

    do {

        cout << "Desea ingresar un nuevo valor? (S/N): ";
        cin >> opcion;

        if (opcion == 'S' || opcion == 's') {

            cout << "Ingrese un valor entero: ";
            cin >> valor;

            Nodo* nuevoNodo = new Nodo;

            nuevoNodo->dato = valor;
            nuevoNodo->siguiente = NULL;

            if (inicio == NULL) {

                inicio = nuevoNodo;
                fin = nuevoNodo;

            } else {
                fin->siguiente = nuevoNodo;
                fin = nuevoNodo;

            }
        }

    } while (opcion == 'S' || opcion == 's');

    cout << "\nContenido de la lista:\n\n";

    Nodo* actual = inicio;

    while (actual != NULL) {

        cout << "[" << actual->dato << " | ";

        if (actual->siguiente != NULL) {

            cout << "* ] -> ";

        } else {

            cout << "NULL]";
        }

        actual = actual->siguiente;
    }

    cout << endl;
    actual = inicio;

    while (actual != NULL) {

        Nodo* auxiliar = actual;
        actual = actual->siguiente;

        delete auxiliar;
    }

    cout << "\nMemoria liberada correctamente." << endl;

    return 0;
}
