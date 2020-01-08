#include <stdio.h>
#include <stdlib.h>
#include "count.h"

int main(int argc, char* argv[]) {
        if(argc != 2)
                printf("Missing arg");
        else 
            printf("%d\n", count_digit(atoi(argv[1])));
        return 1;
}
