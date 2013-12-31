#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FNAME "/home/douzy/plugin_log.txt"
static void _log(char *msg) {
    FILE *log_file = fopen(FNAME, "a");
    if (NULL == log_file) {
        printf("open file error!\n");
        return;
    }

    fwrite(msg, strlen(msg), 1, log_file);
    fwrite("\n", 1, 1, log_file);
    fclose(log_file);
}

int main() {
    _log("hello");
    _log("World!");
    return 0;
}
