#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
        if(argc != 2)
            printf("Missing arg");
        else {
                char *toRev = argv[1];
                size_t length = strlen(toRev);
                for(size_t i = length;i > 0;i--) {
                    printf("%c", *(toRev + i - 1));
                }
        }
        printf("\n");
        return 0;
}
