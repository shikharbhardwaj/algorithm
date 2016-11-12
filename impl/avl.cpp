// To implement an AVL tree
//
#include <iostream>
template <typename data> struct AVL_node {
    data data_inst;
    AVL_node *left, *right, *parent;
    size_t height;
};
template <typename data> class AVL_tree {
    using node = AVL_node<data>;
    node root = nullptr;
    void rotate_left(node *needle) {
        if (needle == nullptr)
            return;
        node *a_left = needle->left;
        node *B = needle->right;
        if (root == needle) {
            // This is the root node, without any parent
            root = B;
        } else {
            if (needle->data < needle->parent->data) {
                needle->parent->left = B;
            } else {
                needle->parent->right = B;
            }
            B->parent = needle->parent;
        }
        needle->right = B->left;
        B->left->parent = needle;
        B->left = needle;
        needle->parent = B;
    }
    void rotate_right(node *needle) {
        if (needle == nullptr)
            return;
        node *a_right = needle->right;
        node *B = needle->left;
        if (root == needle) {
            // This is the root node, without any parent
            root = B;
        } else {
            if (needle->data < needle->parent->data) {
                needle->parent->left = B;
            } else {
                needle->parent->right = B;
            }
            B->parent = needle->parent;
        }
        needle->left = B->right;
        B->right->parent = needle;
        B->right = needle;
        needle->parent = B;
    }

  public:
    AVL_tree(std::initializer_list<data> elems) {
        for (auto elem : elems) {
            insert(elem);
        }
    }
    void insert(data key);
    node *search(data key);
    void remove(data key);
};
int main() {}
