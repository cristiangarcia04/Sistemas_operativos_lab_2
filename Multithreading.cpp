#include <iostream>
#include <pthread.h>

using namespace std;

void* funcionThread(void* arg) {
    cout << "Hello from the created thread." << endl;

    return NULL;
}

int main() {
    pthread_t thread;

    cout << "Hello from the main thread." << endl;

    pthread_create(&thread, NULL, funcionThread, NULL);

    pthread_join(thread, NULL);

    return 0;
}