/**
 * @file 1-2.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 无缓冲I/O函数的使用示例
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 4096


int main(int argc, char **argv)
{
    int n;
    char buffer[BUFFERSIZE];

    while ((n = read(STDIN_FILENO, buffer, BUFFERSIZE)) > 0)
    {
        write(STDOUT_FILENO, buffer, n);
    }
    exit(0);
}