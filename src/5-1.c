/**
 * @file 5-1.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief getopt_long的使用
 * @version 0.1
 * @date 2023-7-3
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void print_help(void)
{
    printf("-M --mgroup assign the multi-broadcast group\n");
    printf("-H --help   assign print the help infomation\n");
}

int main(int argc, char **argv)
{
    // analysis the parameters from terminal
    // -M --mgroup      assign the multi-broadcast group
    // -H --help        assign print the help infomation
    int index = 0;
    struct option argarr[] = {
        {"mgroup", 1, NULL, 'M'},
        {"help", 0, NULL, 'H'},
        {NULL, 0, NULL, 0}};
    int c;
    while (1)
    {
        c = getopt_long(argc, argv, "M:H", argarr, &index);
        if (c < 0)
            break;
        switch (c)
        {
        case 'M':
            printf("mgroup = %s\n", optarg);
            break;
        case 'H':
            print_help();
            exit(0);
            break;
        default:
            break;
        }
    }
}