/**
 * @file 1-5.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 使用进程控制函数简单实现shell，该程序没有实现向指令传递参数的功能
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 4096


int main(int argc, char **argv)
{
    char buffer[BUFFERSIZE];
    pid_t pid;
    int status;

    fprintf(stdout, "%% ");
    while (fgets(buffer, BUFFERSIZE, stdin) != NULL)
    {
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = 0;
        }

        pid = fork();
        if (pid == 0)
        {
            execlp(buffer, buffer, (char *)0);
            exit(0);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
        fprintf(stdout, "%% ");
    }
}