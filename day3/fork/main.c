#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>

int main(void) {
    for(int i = 0;i < 10;i++) {
        pid_t pid = fork();
        if(pid == -1)
            err(1, "fork failed");
        if(pid == 0) {
            for(int j = 0; j < 10;j++) {
                printf("%i: %d\n", j+1, getpid());
            }
            exit(0);
        }
        else {
            int status = 0;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}
