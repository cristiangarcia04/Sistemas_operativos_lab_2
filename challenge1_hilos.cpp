#include <iostream>
#include <vector>
#include <pthread.h>
using namespace std;

struct Args {
    const vector<long long>* a;
    size_t ini, fin;
    long long resultado;
};

void* sumar(void* arg) {
    Args* d = (Args*)arg;
    d->resultado = 0;
    for (size_t i = d->ini; i < d->fin; i++) d->resultado += (*d->a)[i];
    return nullptr;
}

int main() {
    vector<long long> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t mitad = a.size() / 2;

    Args h1{&a, 0, mitad, 0};
    Args h2{&a, mitad, a.size(), 0};

    pthread_t t1, t2;
    pthread_create(&t1, nullptr, sumar, &h1);
    pthread_create(&t2, nullptr, sumar, &h2);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    cout << "Hilo 1: " << h1.resultado << endl;
    cout << "Hilo 2: " << h2.resultado << endl;
    cout << "Total: " << h1.resultado + h2.resultado << endl;
    return 0;
}
