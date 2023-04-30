/**
 * @file 1-1.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief ls功能的简单实现
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main(int argc, char** argv)
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ls directory_name!\n");
        exit(1);
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        fprintf(stderr, "Can't open %s: ", argv[1]);
        perror(NULL);
        exit(1);
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        fprintf(stdout, "%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}