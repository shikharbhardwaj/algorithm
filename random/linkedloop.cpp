#include <iostream>
#include <memory>
//Aim : To detect whether there exists a cycle or not
//in a linked list
struct node{
    int data;
    node *next;
    node(){
        data = 0;
        next = nullptr;
    }
};
class linked_list{
    std::unique_ptr<node> list;
    public:
    linked_list(size_t n){
        list = std::make_unique<node>(new node[n]);
    }
    void link(node* first, node* second){
        second->next = first;
    }
};
