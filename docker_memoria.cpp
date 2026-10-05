#include <iostream>
#include <cstdlib>
using namespace std;

int global_var = 1;                   

void funcion() {}                     

int main() {
    int local = 5;                    
    int* dinamica = new int(7);       

    cout << "Hello World" << endl;
    cout << "Text (codigo, main):  " << (void*)main << endl;
    cout << "Text (codigo, funcion): " << (void*)funcion << endl;
    cout << "Datos (global):       " << &global_var << endl;
    cout << "Heap (new):           " << dinamica << endl;
    cout << "Stack (local):        " << &local << endl;

    delete dinamica;
    return 0;
}
