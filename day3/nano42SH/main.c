#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    // Read stdin
    char cmd[256];
    int r = read(1, cmd, 256);
    char *bash[4] = { "bash", "-c", NULL, NULL };
    bash[2] = cmd;
    
    
    // Fork & Exec
    pid_t pid = fork();
    if(pid == -1) 
        err(1, "Fork failed");
    if(pid == 0) {
        execvp(bash[0], bash);
        exit(errno);
    }
    else {
        int status = 0;
        waitpid(pid, &status, 0);
        if(!WIFEXITED(status)){
            return WEXITSTATUS(status);
        }
    }
    return 0;
}
