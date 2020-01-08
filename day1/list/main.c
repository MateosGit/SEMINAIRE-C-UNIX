#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <ctype.h>
void print_list(t_list *list) {
    t_list *curr = list;
    while(curr != NULL) {
        int *toPrint = curr->data;
        printf("%i, ",*toPrint);
        curr = curr->next;
    }
    printf("\n");
}
int main(void) {
    int a = 2;
    int b = 3;
    int c = 4;
    t_list *list = create_elem(&a);
    list_push_front(&list, &b);
    list_push_front(&list, &c);

    print_list(list);
    return 0;
}
