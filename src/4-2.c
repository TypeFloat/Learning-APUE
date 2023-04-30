/**
 * @file 4-2.c
 * @author Zekun Liu (liuzekun_123@163.com)
 * @brief fputc 和 fgetc 实现文件复制
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    FILE *fps, *fpd;

    fps = fopen(argv[1], "r");
    if (fps == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    fpd = fopen(argv[2], "w");
    if (fps == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }

    int ch;
    while (1)
    {
        ch = fgetc(fps);
        if (ch == EOF)
            break;
        fputc(ch, fpd);
    }


    fclose(fpd);
    fclose(fps);

    exit(0);
}