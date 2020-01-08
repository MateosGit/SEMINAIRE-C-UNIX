#include <err.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   if(argc != 3) 
       err(1, "Invalid args");

   int fd_in = open(argv[1], O_RDONLY);
   int fd_out = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0644);
   if(fd_in == -1 || fd_out == -1)
       err(2, "open syscall error");

   int r;
   char buff[32];
   while( (r = read(fd_in, buff, 32))) {
        for(int i = 0;i < r; i++) {
            if(isupper(buff[i])) 
                buff[i] = ((buff[i] + 13 - 65) % 26) + 65;
            if(islower(buff[i]))
                buff[i] = ((buff[i] + 13 - 97) % 26) + 97;
        }
        r = write(fd_out, buff, r);
        if(r == -1)
            err(2, "write syscall error");
   }
   close(fd_in);
   close(fd_out);
   return 0;
}
