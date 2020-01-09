#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if(argc != 2)
        err(-1, "Missing args");

    int fd[2];
    int r_pipe = pipe(fd);
    if(r_pipe == -1) 
        exit(errno);

    pid_t pid = fork();

    if(pid == -1)
        err(3, "fork failed");

    if(pid == 0) {
        close(fd[0]);
        int w = write(fd[1], argv[1], strlen(argv[1]));
        if(w == -1)
            err(-2, "syscall error");
        close(fd[1]);
        exit(w);
    }
    else {
        int status = 0;
        waitpid(pid, &status, 0);
        
        close(fd[1]);
        int r;
        char buff[256];
        while( r = read(fd[0], buff, 256)) {
            if(r == -1)
                err(-2, "syscall error");
            r = write(1, buff, r);
            if(r == -1)
                err(-2, "syscall error");
        }
        close(fd[0]);

        return WEXITSTATUS(status);
    }
}
