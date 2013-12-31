#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 7323
#define BACKLOG 5

#define LOG(...) printf("[TEST] : ");\
		printf(__VA_ARGS__);\
		printf("\n");

typedef struct sockaddr_in sockaddr_in;

int sockfd, clientfd;
static char *ip_addr = "10.120.137.100";

int main() {
    sockaddr_in addr;
    sockaddr_in client_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
	LOG("can not get socket FD.");
	return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    // addr.sin_port = htons(0); // choose a random unused port.
    // addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // set IP as itself.
    bzero(&(addr.sin_zero), strlen(addr.sin_zero));

    // remember to cast the <struct sockaddr_in*> to <struct sockaddr*>,
    // and the size is sizeof(struct sockaddr).
    int res = bind(sockfd, (struct sockaddr*)(&addr), sizeof(struct sockaddr));
    if (res < 0) {
	LOG("bind socket failed!");
	return -1;
    }

    LOG("bind socket success!");
    if (listen(sockfd, BACKLOG) < 0) {
	LOG("listen failed!");
    }

    int addrlen = sizeof(struct sockaddr_in);
    clientfd = accept(sockfd, (struct sockaddr*)(&client_addr), &addrlen);
    if (clientfd < 0) {
	LOG("accept failed!");
	return -1;
    }

    const char *msg = "Hello client!\n";
    int mres = send(clientfd, msg, strlen(msg), 0);
    LOG("%d chars has been sent to client...", mres);

    char *rmsg = (char *)malloc(128);
    memset(rmsg, 0, strlen(rmsg));
    mres = recv(clientfd, rmsg, 128, 0);
    LOG("<server recv> %d", mres);
    rmsg[mres] = '\0';
    LOG("recv : %s", rmsg);
    free(rmsg);
    
    close(clientfd);
    close(sockfd);
    return 0;
}
