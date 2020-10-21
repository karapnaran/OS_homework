#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argn, char* argv[])
{
    //the program should take two arguments the source path followed by the destination path.
    if (argn != 3)
    {
        printf("Wrong argument count.\n");
        return 1;
    }

    const char* src_path = argv[1];
    const char* dst_path = argv[2];

    int src_fd = open(src_path, O_RDONLY);
    int dst_fd = open(dst_path, O_CREAT | O_WRONLY);

    //calculating the size of the source file
    off_t src_off = lseek(src_fd, 0, SEEK_END);
    if (src_off ==-1)
    {
        return errno;
    }
    
    //copying the file
    unsigned char buffer[4096];
    while (1) 
    {
        int err = read(src_fd, buffer, 4096);
        if (err == -1) 
        {
            return errno;
        }
        int n = err;
        if (n == 0) break;
        err = write(dst_fd, buffer, n);
        if (err == -1) 
	{
            return errno;
        }
    }

    //calculating the size of the copied file
    off_t dst_off = lseek(dst_fd, 0, SEEK_END);
    if (src_off ==-1)
    {
        return errno;
    }

    printf("Size of the source file is %ld bytes \n", src_off);
    printf("Size of the copied file is %ld bytes \n", dst_off);

    //closing both files
    close(src_fd);
    close(dst_fd);
}
