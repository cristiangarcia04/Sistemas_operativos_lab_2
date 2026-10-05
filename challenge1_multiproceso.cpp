#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    vector<long long> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t mitad = a.size() / 2;

    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); return 1; }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {                   
        close(fd[0]);
        long long suma2 = 0;
        for (size_t i = mitad; i < a.size(); i++) suma2 += a[i];
        write(fd[1], &suma2, sizeof(suma2));
        close(fd[1]);
        return 0;
    }

    close(fd[1]);
    long long suma1 = 0;
    for (size_t i = 0; i < mitad; i++) suma1 += a[i];

    long long suma2 = 0;
    read(fd[0], &suma2, sizeof(suma2));   
    close(fd[0]);
    wait(nullptr);

    cout << "Suma primera mitad (padre): " << suma1 << endl;
    cout << "Suma segunda mitad (hijo):  " << suma2 << endl;
    cout << "Total: " << suma1 + suma2 << endl;
    return 0;
}
