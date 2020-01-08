#include "list.h"
#include "err.h"
#include <stdio.h>
#include <stdlib.h>

t_list *create_elem(void* data) {
    t_list *new = calloc(1, sizeof(t_list));
    if(!new) 
        errx(1, "create_elem: calloc failed");
    new->data = data;
    return new;
}

void list_push_end(t_list **begin_list, void *data) {
    t_list *list = *begin_list;
    t_list *toPush = create_elem(data);
    while(list->next != NULL)
        list = list->next;
    list->next = toPush;
}

void list_push_front(t_list **begin_list, void *data) {
    t_list *toPush = create_elem(data);
    t_list *curr = *begin_list;
    toPush->next = curr;
    *begin_list = toPush;
}

void list_push_idx(t_list **begin_list, void *data, int indx) {
    if(indx == 0)
        list_push_front(begin_list, data);
    else
    {
        t_list *curr = *begin_list;
        int count = 0;
        while(curr != NULL && count != indx-1) {
            curr = curr->next;
            count++;
        }
        if(count != indx-1) {
            list_push_end(begin_list, data);
        }
        else {
            t_list *new = create_elem(data);
            t_list *tmp = curr->next;
            new->next = tmp;
            curr->next = new;
        }
    }
}


void list_delete_element(t_list **begin_list, int indx) {
    if(indx == 0) {
        t_list *curr = *begin_list;
        *begin_list = curr->next;
    }
    int count = 1;
    t_list *curr = *begin_list;
    t_list *then = curr->next;
    while(then != NULL && count != indx) {
        curr = then;
        then = then->next;
        count++;
    }
    if(count == indx && then != NULL) {
        curr->next = then->next;
    }
    else if (count == indx) 
        curr->next = NULL;
    free(then);    
}
