// Implement an AVL tree
#include <iostream>
#include <vector>
typedef struct node {
    int val;
    node *left, *right;
    int ht;
} node;
int get_height(node *cur) {
    if (cur == nullptr)
        return -1;
    return cur->ht;
}
node *insert(node *root, int val) {
    if (root == nullptr) {
        node *z = new node;
        z->val = val;
        z->ht = 0;
        return z;
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    root->ht = 0;
    int left_ht, right_ht;
    left_ht = get_height(root->left);
    right_ht = get_height(root->right);
    if (std::abs(left_ht - right_ht) > 1) {
        // Unbalanced here
        std::cout << "\nUnbalanced at : " << root->val;
    }
    root->ht = std::max(left_ht, right_ht);
    root->ht++;
    return root;
}
void end_bst(node *root) {
    if (root != NULL) {
        end_bst(root->left);
        end_bst(root->right);
        free(root);
    }
}
void new_level(int num) {
    printf("└");
    while (num--) {
        printf("─");
    }
}
void indent(int num) {
    for (int i = 1; i <= num; i++) {
        if ((i - 1) % 5 == 0 && i != 1) {
            printf("│");
        } else {
            printf(" ");
        }
    }
}
void display(node *cur, int level) {
    if (cur == NULL) {
        return;
    }
    indent(5 * level);
    new_level(3);
    printf(" %d:%d\n", cur->val, cur->ht);
    display(cur->left, level + 1);
    display(cur->right, level + 1);
}
int main() {
    node *root = nullptr;
    root = insert(root, 5);
    std::cout << "\nDone";
    root = insert(root, 3);
    std::cout << "\nDone";
    root = insert(root, 2);
    std::cout << "\n";
    // std::cout << "\nDone";
    // root = insert(root, 1);
    // std::cout << "\nDone";
    // root = insert(root, 0);
    // std::cout << "\nDone";
    // root = insert(root, 4);
    // std::cout << "\nDone";
    // root = insert(root, 7);
    // std::cout << "\nDone";
    // root = insert(root, 6);
    // std::cout << "\nDone";
    // root = insert(root, 9);
    // std::cout << "\nDone";
    // root = insert(root, 10);
    display(root, 0);
    end_bst(root);
}
