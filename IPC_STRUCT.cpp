#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

struct Mensaje {
    char texto[100];
};

int main() {
    int pipefd[2];

    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[1]);

        Mensaje mensaje;

        read(pipefd[0], &mensaje, sizeof(mensaje));

        cout << "Child received: " << mensaje.texto << endl;

        close(pipefd[0]);
    }
    else {
        close(pipefd[0]);

        Mensaje mensaje;

        strcpy(mensaje.texto, "Hello child, this is the parent!");

        write(pipefd[1], &mensaje, sizeof(mensaje));

        cout << "Parent sent: " << mensaje.texto << endl;

        close(pipefd[1]);
    }

    return 0;
}