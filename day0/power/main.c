#include <stdio.h>
#include <stdlib.h>
#include "power.h"

int main(int argc, char* argv[]) {
        if(argc != 3) 
            printf("Missing arg");
        else 
            printf("%d\n", my_pow(atoi(argv[1]), atoi(argv[2])));
        return 1;
}
