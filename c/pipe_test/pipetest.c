#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define LOG(...) printf("[PIPE TEST] : ");\
                printf(__VA_ARGS__);\
                printf("\n");

int main() {

    int pipe_fd[2];
    pid_t pid;
    char read_msg[128];
    char write_msg[128];

    int write_num, read_num;

    if (pipe(pipe_fd) < 0) {
        LOG("create pipe error!");
        return -1;
    }

    memset(read_msg, 0, sizeof(read_msg));
    memset(write_msg, 0, sizeof(write_msg));

    if ((pid = fork()) == 0) {
        close(pipe_fd[0]);
        // 10ms. to make sure parent process close its
        // write pipe.
        usleep(10000);
        strcpy(write_msg, "Hello World!");
        write_num = write(pipe_fd[1], write_msg, sizeof(write_msg));
        LOG("size of writing is :%d", write_num);
        close(pipe_fd[1]);
    } else if (pid > 0) {
        close(pipe_fd[1]);
        // 20ms, to make sure the child process has wrote
        // its message already.
        read_num = read(pipe_fd[0], read_msg, sizeof(read_msg));
        LOG("size of reading is :%d", read_num);
        LOG("the content from pipe is : %s", read_msg);
        close(pipe_fd[0]);
    }

    return 0;

}
