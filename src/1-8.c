/**
 * @file 1-8.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 使用进程控制函数简单实现shell，该程序没有实现向指令传递参数的功能
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void func(int signo)
{
    fprintf(stdout, "检测到中断 %d\n", signo);
}


int main(int argc, char **argv)
{
    while (1)
    {
        signal(SIGINT, func);
    }
}