/**
 * @file 3-1.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 标准I/O的效率测试
 * @version 0.1
 * @date 2022-12-2
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <sys/time.h>
#include <sys/times.h>
#include <stdio.h>
#include <stdlib.h>


void f1(void)
{
    int ch;
    while ((ch = getc(stdin)) != EOF)
    {
        putc(ch, stdout);
    }
}

void f2(void)
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF)
    {
        fputc(ch, stdout);
    }
}

void f3(void)
{
    char buffer[2048];
    while (fgets(buffer, 2048, stdin) != NULL)
    {
        fputs(buffer, stdout);
    }
}


int main(int argc, char **argv)
{
    struct tms st;
    clock_t start_time = times(&st);
    switch (atoi(argv[1]))
    {
    case 1:
        f1();
        break;
    case 2:
        f2();
        break;
    case 3:
        f3();
        break;
    default:
        fprintf(stdout, "Usage: ./5-1 (1/2/3)");
        exit(1);
    }
    struct tms et;
    clock_t end_time = times(&et);
    fprintf(stdout, "用户CPU时间：%lu，系统CPU时间：%lu，时钟时间：%lu\n", 
                    et.tms_utime-st.tms_utime,
                    et.tms_stime-st.tms_stime,
                    end_time-start_time);
    exit(0);
}