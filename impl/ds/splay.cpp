#include <iostream>
typedef struct node {
    int key;
    node *left, *right, *parent;
    node() : left(nullptr), right(nullptr), parent(nullptr) {}
    node(int key_)
        : key(key_), left(nullptr), right(nullptr), parent(nullptr) {}
} node;
