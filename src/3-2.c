/**
 * @file 3-2.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief I/O效率的对比
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <sys/types.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    int n;
    for (int buffersize = 1; buffersize <= 524288; buffersize *= 2)
    {
        char buffer[buffersize];
        int fd = open("temp.txt", O_RDONLY);
        int fd2 = open("temp2.txt", O_WRONLY|O_CREAT|O_TRUNC);
        struct tms st;
        clock_t start_time = times(&st);
        while ((n = read(fd, buffer, buffersize)) > 0)
        {
            write(fd2, buffer, n);
        }
        struct tms et;
        clock_t end_time = times(&et);
        fprintf(stdout, "缓冲区大小：%d，用户CPU时间：%lu，系统CPU时间：%lu，时钟时间：%lu\n", 
                        buffersize,
                        et.tms_utime-st.tms_utime,
                        et.tms_stime-st.tms_stime,
                        end_time-start_time);

        close(fd);
        close(fd2);
    }
    exit(0);
}