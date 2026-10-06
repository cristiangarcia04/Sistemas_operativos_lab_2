#include <iostream>
#include <pthread.h>

using namespace std;

struct Datos {
    int numero;
};

void* calcularFactorial(void* arg) {
    Datos* datos = (Datos*)arg;

    long long factorial = 1;

    for (int i = 1; i <= datos->numero; i++) {
        factorial = factorial * i;
    }

    cout << "Thread: factorial of "
         << datos->numero
         << " = "
         << factorial << endl;

    return NULL;
}

int main() {
    int n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    Datos d1;
    Datos d2;
    Datos d3;

    d1.numero = n1;
    d2.numero = n2;
    d3.numero = n3;

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    pthread_create(&thread1, NULL, calcularFactorial, &d1);
    pthread_create(&thread2, NULL, calcularFactorial, &d2);
    pthread_create(&thread3, NULL, calcularFactorial, &d3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    cout << "Main thread finished." << endl;

    return 0;
}