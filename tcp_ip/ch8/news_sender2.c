#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char **argv) {
    int send_sock;
    struct sockaddr_in board_adr;
    FILE *fp;
    char buf[BUF_SIZE];
    int so_brd = 1;
    if (argc != 4) {
        printf("Usage: %s <BroadcastIP> <port> <FilePath>\n", argv[0]);
        exit(1);
    }

    send_sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&board_adr, 0, sizeof(board_adr));
    board_adr.sin_family = AF_INET;
    board_adr.sin_addr.s_addr = inet_addr(argv[1]);
    board_adr.sin_port = htons(atoi(argv[2]));

    setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd,
               sizeof(so_brd));
    if ((fp = fopen(argv[3], "r")) == NULL) {
        error_handling("fopen() error!");
    }

    while (!feof(fp)) {
        fgets(buf, BUF_SIZE, fp);
        sendto(send_sock, buf, strlen(buf), 0, (struct sockaddr *)&board_adr,
               sizeof(board_adr));
        sleep(2);
    }
    fclose(fp);
    close(send_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}