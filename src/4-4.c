/**
 * @file 4-3.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief fwrite 和 fread 实现文件复制
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

    char buf[BUFSIZ];
    int length;
    while (1)
    {
        length = fread(buf, 1, BUFSIZ, fps);
        if (length <= 0)
            break; 
        fwrite(buf, 1, length, fpd);
    }

    fclose(fpd);
    fclose(fps);

    exit(0);
}