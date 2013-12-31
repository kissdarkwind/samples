#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PLOG_PATH "/home/douzy/plugin_log.txt"

#define PLOG(...) do {\
            FILE *log_file = fopen(PLOG_PATH, "a");\
            if (NULL == log_file)\
                break;\
            char* msg = malloc(256);\
            bzero(msg, 256);\
            sprintf(msg, __VA_ARGS__);\
            fwrite(msg, strlen(msg), 1, log_file);\
            fwrite("\n", 1, 1, log_file);\
            fclose(log_file);\
            free(msg);\
            } while (0);

int main() {
    PLOG("Hello");
    PLOG("World!");

    int d = 1001;
    PLOG("the number is : %d", d);
}
