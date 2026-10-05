#include <iostream>
using namespace std;

int main() {
    int x = 10;                      
    cout << "Valor: " << x << ", direccion: " << &x << endl;  

    int* p = &x;
    *p = 25;                          
    cout << "Valor: " << x << ", direccion: " << &x << endl;  
    return 0;
}
