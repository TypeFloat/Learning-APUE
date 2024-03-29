
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    char message[BUF_SIZE];
    int str_len;
    socklen_t addr_size;

    struct sockaddr_in serv_addr;
    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // 1. socket()
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        error_handling("UDP socket() error!");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;  // IPv4
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // 2. connect
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        fputs("Input message(Q to quit): ", stdout);
        fgets(message, BUF_SIZE, stdin);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }
        // 3. write
        write(sock, message, strlen(message));

        // 4. read
        str_len = read(sock, message, sizeof(message) - 1);
        message[str_len] = 0;
        printf("Message from server: %s", message);
    }

    // 5. close()
    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}