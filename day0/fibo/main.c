#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"

int main(int argc, char *argv[]){
    if(argc != 2) {
        printf("Only one argument is needed");
    }
    else {
        printf("%ld\n", fibonacci(atoi(argv[1])));
    }
    return 1;
}
