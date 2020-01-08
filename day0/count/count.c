#include <stdio.h>

int count_digit(int a) {
        int res = 0;
        while(a != 0) {
                res++;
                a = a/10;
        }
        return res;
}
