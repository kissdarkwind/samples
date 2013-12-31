#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int goon = 1;

void thread() {

    int count = 0;
    while (goon) {
        ++count;
        printf("____thread count : %d\n", count);
        usleep(500000);

        if (count == 30)
            return;
    }

}

int main() {

    pthread_t id;
    int ret;

    ret = pthread_create(&id, NULL, (void *)thread, NULL);
    if (ret != 0) {
        printf("something wrong...\n");
        return -1;
    }

    usleep(3000000);
    int main_goon = 1;
    int main_count = 0;

    while (main_goon) {
        ++main_count;
        printf("____main count : %d\n", main_count);
        usleep(500000);
        if (main_count == 10) {
            ret = pthread_join(id, NULL);
            if (ret != 0) {
                printf("something wrong...\n");
                return -2;
            } else {
                printf("thread has join main thread!\n");
            }
        }

        if (main_count == 30)
            return 0;
    }

    return 0;

}