#include <stdlib.h>
#include <stdio.h>

void print_array(int *tab, int size) {
    for(int i = 0; i <= size;i++)
        printf("%d\n", tab[i]);
}

int main(void) {
    int *arr = calloc(5, sizeof(int));
    print_array(arr, 4);
}
