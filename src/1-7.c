/**
 * @file 1-7.c
 * @author Return0 (liuzekun_123@163.com)
 * @brief uid和gid的获取
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
    fprintf(stdout, "用户ID：%d\n", getuid());
    fprintf(stdout, "组ID：%d\n", getgid());
    exit(0);
}