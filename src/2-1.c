/**
 * @file 2-1.c
 * @author TypeFloat (liuzekun_123@163.com)
 * @brief 空洞文件的创建
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>


int main(int argc, char **argv)
{
    int fd = creat("hole_file.txt", (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    
    write(fd, "hello world", 11);
    lseek(fd, 100, SEEK_SET);
    write(fd, "hello world", 11);
    
    close(fd);
    exit(0);
}