#include <iostream>
using namespace std;

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    int *puntero = numeros;

    cout << "Direccion del arreglo: " << numeros << endl;
    cout << "Direccion guardada por el puntero: " << puntero << endl;

    cout << endl;

    cout << "Elementos del arreglo:" << endl;

    cout << *puntero << endl;
    cout << *(puntero + 1) << endl;
    cout << *(puntero + 2) << endl;
    cout << *(puntero + 3) << endl;
    cout << *(puntero + 4) << endl;

    *(puntero + 2) = 100;

    cout << endl;

    cout << "Arreglo despues de modificar:" << endl;

    cout << numeros[0] << endl;
    cout << numeros[1] << endl;
    cout << numeros[2] << endl;
    cout << numeros[3] << endl;
    cout << numeros[4] << endl;

    return 0;
}