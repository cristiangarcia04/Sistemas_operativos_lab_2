#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;                      
    *p = 20;                          
    cout << "Tras puntero: x = " << x << endl;

    int& r = x;        
    r = 30;
    cout << "Tras referencia: x = " << x << endl;

    cout << "Direccion de x:                  " << &x << endl;
    cout << "Direccion almacenada en p:       " << p << endl;
    cout << "Direccion del puntero p (&p):    " << &p << endl;
    cout << "Direccion a la que apunta r:     " << &r << endl;
    return 0;
}
