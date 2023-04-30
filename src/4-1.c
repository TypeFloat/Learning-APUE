/**
 * @file 4-1.c
 * @author Zekun Liu (liuzekun_123@163.com)
 * @brief fopen() fclose() 的使用示例
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(int argc, char **argv)
{

    FILE *fp;
    fp = fopen("tmp", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(1);
    }

    puts("OK!");
    fclose(fp);
    exit(0);
}