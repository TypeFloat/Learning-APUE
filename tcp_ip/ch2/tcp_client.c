#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;
    int idx = 0, read_len = 0;

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // 1. socket() 建立流式套接字，即TCP
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error!");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;  // IPv4
    // inet_addr可以直接将点分式地址转为网络字节序的二进制地址，因此不需要进行字节序转换
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // 2. connect() 请求连接
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error!");
    }

    // 3. read/write() 读写数据
    while (1) {
        read_len = read(sock, &message[idx++], 1);
        if (read_len == 0) break;
        if (read_len == -1) {
            error_handling("read() error!");
        }

        str_len += read_len;
    }

    printf("Message from server: %s\n", message);
    printf("Function read call count: %d\n", str_len);
    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}