#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    int fd;
    fd = open("/home/douzy/tempcode/c/mmap/data", O_RDWR);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("stat");
        return -1;
    }

    printf("file size : %d\n", (unsigned int)sb.st_size);

    char* buf;

    // ________________________________________________________________________________
    //|  offset      valid mmap                                                        |
    //|  ___________________________                                                   |
    //| |_________|/////////////////|                                                  |
    //|                                                                                |
    //|                page1           page2       page3          page4      page5     |
    //|            __________________________________________________________________  |
    //|           |/////////////|/////////////|_____________|____________|___________| |
    //|                                                                                |
    //|                 valid                          BUS error                       |
    //|________________________________________________________________________________|
    //
    size_t size = sb.st_size;//1024 * 6;

    buf = mmap(NULL, /*sb.st_size*/size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("mmap ret : %p    MAP_FAILED: %p\n", buf, MAP_FAILED);

    if (buf == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    close(fd);

    buf[0] = '2';

    if (munmap(buf, /*sb.st_size*/size) == -1) {
        perror("munmap");
        return -1;
    }
    return 0;
}