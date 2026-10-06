#include <iostream>
#include <unistd.h>

using namespace std;

long long factorial(int n) {
    long long resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado = resultado * i;
    }

    return resultado;
}

int main() {
    int n1, n2;

    cin >> n1 >> n2;

    pid_t pid = fork();

    if (pid == 0) {
        cout << "Child process: " << factorial(n1) << endl;
    }
    else {
        cout << "Parent process: " << factorial(n1) << endl;
    }

    return 0;
}