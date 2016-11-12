#include <iostream>
#include <memory>
// Implement a BST as a linked list
template <typename T> struct node {
    T data;
    std::unique_ptr<node> left, right;
    node() = default;
    node(const T &in_data) { data = in_data; }
    node(T &&in_data) { data = in_data; }
};
template <typename T> class BST {
    node<T> root;

  public:
    BST() = default;
};
int main() {}
