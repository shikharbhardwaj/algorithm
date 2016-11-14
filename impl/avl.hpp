// To implement an AVL tree
//
#include <bitset>
#include <iostream>
#include <sstream>
template <typename data> struct AVL_node {
    data key;
    AVL_node *left = nullptr, *right = nullptr, *parent = nullptr;
    size_t height;
};
template <typename T> size_t get_height(AVL_node<T> *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
template <typename data> class AVL_tree {
    using node = AVL_node<data>;
    node *root = nullptr;
    size_t num = 0;
    void update_height(node *cur) {
        if (cur == nullptr) {
            return;
        }
        node *left = cur->left, *right = cur->right;
        cur->height = 1;
        if (left) {
            cur->height = left->height + 1;
        }
        if (right) {
            cur->height = std::max(cur->height, right->height + 1);
        }
    }
    node *rotate_left(node *needle) {
        node *B = needle->right;
        if (root == needle) {
            // This is the root node, without any parent
            root = B;
        } else {
            if (needle->key < needle->parent->key) {
                needle->parent->left = B;
            } else {
                needle->parent->right = B;
            }
        }
        B->parent = needle->parent;
        needle->right = B->left;
        if (B->left != nullptr) {
            B->left->parent = needle;
        }
        B->left = needle;
        needle->parent = B;
        update_height(needle);
        update_height(B);
        return B;
    }
    node *rotate_right(node *needle) {
        node *B = needle->left;
        if (root == needle) {
            // This is the root node, without any parent
            root = B;
        } else {
            if (needle->key < needle->parent->key) {
                needle->parent->left = B;
            } else {
                needle->parent->right = B;
            }
        }
        B->parent = needle->parent;
        needle->left = B->right;
        if (B->right != nullptr) {
            B->right->parent = needle;
        }
        B->right = needle;
        needle->parent = B;
        update_height(needle);
        update_height(B);
        return B;
    }
    void new_level(std::stringstream &out, int num) {
        out << "└";
        while (num--) {
            out << "─";
        }
    }
    void indent(std::stringstream &out, int num) {
        for (int i = 1; i <= num; i++) {
            if ((i - 1) % 5 == 0 && i != 1) {
                out << "│";
            } else {
                out << " ";
            }
        }
    }
    void display(node *cur, int level, std::stringstream &out) {
        if (cur == NULL) {
            return;
        }
        indent(out, 5 * level);
        new_level(out, 3);
        out << " " << cur->key << "(" << cur->height << ")\n";
        display(cur->left, level + 1, out);
        display(cur->right, level + 1, out);
    }
    void end_tree(node *cur) {
        if (cur != nullptr) {
            end_tree(cur->left);
            end_tree(cur->right);
            delete cur;
        }
    }

  public:
    AVL_tree() = default;
    AVL_tree(std::initializer_list<data> elems) {
        for (auto elem : elems) {
            insert(elem);
        }
        num = elems.size();
    }
    void augment(node *needle) {
        if (needle == nullptr) {
            return;
        }
        // First augment the height
        node *left = needle->left, *right = needle->right;
        update_height(needle);
        // Then check if imbalanced
        size_t l_height = get_height(left);
        size_t r_height = get_height(right);
        int balance_factor = l_height - r_height;
        if (balance_factor > 1) {
            if (get_height(left->right) >= 1) {
                rotate_left(left);
            }
            needle = rotate_right(needle);
        } else if (balance_factor < -1) {
            if (get_height(right->left) >= 1) {
                rotate_right(right);
            }
            needle = rotate_left(needle);
        }
        augment(needle->parent);
    }
    void insert(data key) {
        node *cur = root, *parent = nullptr;
        while (cur != nullptr) {
            parent = cur;
            if (key < cur->key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        cur = new node();
        cur->parent = parent;
        cur->key = key;
        cur->height = 1;
        if (parent == nullptr) {
            root = cur;
        } else {
            if (key < parent->key) {
                parent->left = cur;
            } else {
                parent->right = cur;
            }
        }
        augment(cur);
        num += 1;
    }
    node *search(data key) {
        node *cur = root;
        while (cur != nullptr) {
            if (cur->key == key) {
                break;
            }
            if (key < cur->key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return cur;
    }
    void remove(node *needle);
    std::string to_string() {
        // Give a string representation
        std::stringstream rep;
        display(root, 0, rep);
        return rep.str();
    }
    size_t size() const { return num; }
    ~AVL_tree() { end_tree(root); }
};
