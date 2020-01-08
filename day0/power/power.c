#include <stdio.h>

int my_pow(int a, int b) {
    int res = 1;
    for(size_t i = 0; i < b;i++){
        res = res * a;
    }
    return res;
}
