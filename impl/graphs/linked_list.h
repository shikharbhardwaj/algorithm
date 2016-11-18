#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int node_data;
typedef struct node node;
typedef struct linked_list {
    node *first;
    int size;
} list;
typedef struct node {
    node_data data;
    node *next;
} node;
list *init_list() {
    list *new_list = (list *)malloc(sizeof(list));
    new_list->size = 0;
    new_list->first = NULL;
    return new_list;
}
node *init_node(node_data val) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}
node *find_node(list *data_list, node_data val) {
    node *cur = data_list->first;
    while (cur != NULL) {
        if (cur->data == val)
            return cur;
    }
    return NULL;
}
void add_node(list *data_list, node *in) {
    node *cur = data_list->first, *prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) {
        data_list->first = in;
    } else {
        prev->next = in;
    }
}
void remove_node(list *data_list, node *in) {
    node *cur = data_list->first, *prev = NULL;
    while (cur != in) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) {
        data_list->first = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
}
void remove_data(list *data_list, node_data val) {
    node *needle = find_node(data_list, val);
    remove_node(data_list, needle);
}
#endif
