#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int pipefd[2];

    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[1]);

        char mensaje[100];

        read(pipefd[0], mensaje, sizeof(mensaje));

        cout << "Child received: " << mensaje << endl;

        close(pipefd[0]);
    }
    else {
        close(pipefd[0]);

        char mensaje[] = "Hello from parent!";

        write(pipefd[1], mensaje, strlen(mensaje) + 1);

        cout << "Parent sent: " << mensaje << endl;

        close(pipefd[1]);
    }

    return 0;
}