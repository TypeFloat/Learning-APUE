/**
 * @file 1-4.c
 * @author Return0 (liuzekun_123@163.com)
 * @brief 获取进程ID号
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    fprintf(stdout, "Hello world from process ID %ld.\n", getpid());
    exit(0);
}