#include <benchmark/benchmark.h>
#include <iostream>
#include <sstream>
typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    int ht;
} node;
int get_ht(node *in) {
    if (in == nullptr) {
        return -1;
    }
    return in->ht;
}
node *rotate_left(node *needle) {
    node *B = needle->right;
    node *B_left = B->left;
    B->left = needle;
    needle->right = B_left;
    needle->ht = std::max(get_ht(needle->left), get_ht(needle->right)) + 1;
    B->ht = std::max(get_ht(B->left), get_ht(B->right)) + 1;
    return B;
}
node *rotate_right(node *needle) {
    node *B = needle->left;
    node *B_right = B->right;
    B->right = needle;
    needle->left = B_right;
    needle->ht = std::max(get_ht(needle->left), get_ht(needle->right)) + 1;
    B->ht = std::max(get_ht(B->left), get_ht(B->right)) + 1;
    return B;
}
node *insert(node *root, int new_val) {
    if (root == nullptr) {
        root = new node;
        root->val = new_val;
        root->ht = 0;
        root->left = root->right = nullptr;
    } else {
        if (new_val < root->val) {
            root->left = insert(root->left, new_val);
        } else {
            root->right = insert(root->right, new_val);
        }
        node *left = root->left;
        node *right = root->right;
        int left_ht = get_ht(left);
        int right_ht = get_ht(right);
        root->ht = std::max(left_ht, right_ht) + 1;
        int balance_factor = left_ht - right_ht;
        if (balance_factor > 1) {
            // Check if LR
            if (get_ht(left->right) - get_ht(left->left) >= 1) {
                // Rotate tree rooted at left child towards left
                root->left = rotate_left(left);
            }
            // Rotate the tree rooted at root towards right
            root = rotate_right(root);
        }
        if (balance_factor < -1) {
            // Check if RL
            if (get_ht(right->left) - get_ht(right->right) >= 1) {
                // Rotate tree rooted at right child towards right
                root->right = rotate_right(right);
            }
            // Rotate the tree rooted at root towards left
            root = rotate_left(root);
        }
    }
    return root;
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
    out << " " << cur->val << "(" << cur->ht << ")\n";
    display(cur->left, level + 1, out);
    display(cur->right, level + 1, out);
}
std::string to_string(node *root) {
    std::stringstream ss;
    display(root, 0, ss);
    return ss.str();
}
int main() {}
