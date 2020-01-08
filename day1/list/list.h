#ifndef LIST_H
#define LIST_H

typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

t_list *create_elem(void *data);
void list_push_end(t_list **begin_list, void *data);
void list_push_front(t_list **begin_list, void *data);
void list_push_idx(t_list **begin_list, void *data, int indx);
void list_delete_element(t_list **begin_list, int indx);

#endif
