/**
 * @file 1-3.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 标准I/O函数的使用示例
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>


int main(int argc, char **argv)
{
    char ch;

    while ((ch = getc(stdin)) != EOF)
    {
        putc(ch, stdout);
    }
}