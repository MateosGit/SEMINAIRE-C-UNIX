#include <err.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if(argc < 2)
        err(1, "minicat: no file given");
    if(argc > 2)
        err(1, "minecat: too many arguments");

    printf("file to open: %s\n", argv[1]);

    int fd_in = open(argv[1], O_RDONLY);
    if(fd_in == -1)
        err(2, "minicat: can't open '%s': No such file or directory", argv[1]);
    
    int r;
    char buff[32];
    
    while((r = read(fd_in, buff, 32)) != 0) 
    {
        if(r == -1)
            err(3, "minicat: read syscall error.");
        int i = 0;
        int wr;
        int count = 0;
        while(i < r) {
            if(buff[i] == '\n') {
                count += i;
                wr = write(1, buff, i);
                if(wr == -1) 
                    err(3, "minicat: syscall error");
                wr = write(1, "$", 1);
            }
            i++;
        }
        wr = write(1, buff, r - count);
    }
    
    close(fd_in);
    return 0;
}
