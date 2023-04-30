/**
 * @file 1-6.c
 * @author Return0 (liuzekun_123@163.com)
 * @brief perrno和strerror的使用方法示例
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <sys/errno.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
    fprintf(stderr, "访问权限错误：%s\n", strerror(EACCES));
    errno = ENOENT;
    perror("找不到文件：");
}