#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 2 || argc > 3) {
        err(1, "Missing args");
    }
    int fd_in = 0;
    if(argc == 3) {
        fd_in = open(argv[2], O_RDONLY);
    }
    int r;
    char buff[32];
    if(fd_in == 0)
        printf("reading stdin");
    int count = 0;
    while( (r = read(fd_in, buff, 32))) {
        if(r == -1)
            err(2, "read syscall error");
        if(argv[1][1] == 'm') {
            for(int i = 0;i < r;i++) {  
                if(isalpha(buff[i])) 
                    count++;
            }
        }
        if(argv[1][1] == 'w') {
            int i = 0;
            while(i < r) {
                while(i < r && isblank(buff[i]) == 0) {
                    i++;
                }
                count++;
                i++;
            }
        }
        if(argv[1][1] == 'l') {
            for(int i = 0;i < r;i++) {
                if(buff[i] == '\n') 
                    count++;
            }
        }
    }

    // ITOA COUNT CONVERSION AND WRITING
    char buffer[2];
    sprintf(buffer, "%d", count);
    int wr = write(1, buffer, 2);
    if(wr == -1) 
        err(2, "write syscall error");
    close(fd_in);
    return 0;
}
