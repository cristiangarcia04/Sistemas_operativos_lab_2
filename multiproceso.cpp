#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();           

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        cout << "[HIJO]  PID: " << getpid() << ", PPID (padre): " << getppid() << endl;
    } else {
        cout << "[PADRE] PID: " << getpid() << ", PID del hijo: " << pid << endl;
        wait(nullptr);
    }
    return 0;
}
