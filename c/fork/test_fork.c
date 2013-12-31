#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("now the main pid is %d\n", pid);

    pid_t opid;
    opid = fork();

    if (opid < 0) {
        printf("something error!\n");
    } else if (opid == 0) {
        printf("I am the child process! and res is : %d\n", opid);
        return;
    } else {
        printf("I am the parent process! and res is : %d\n", opid);
    }

    printf("Who print me ?!\n");

    return 0;
}
