#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *left, *right;
    struct node *parent;
} node;
typedef struct bst {
    node *root;
    int N;
} bst;
bst *new_bst() {
    bst *tree = (bst *)malloc(sizeof(bst));
    tree->root = NULL;
    tree->N = 0;
    return tree;
}
void end_bst(node *root) {
    if (root != NULL) {
        end_bst(root->left);
        end_bst(root->right);
        free(root);
    }
}
node *new_node(int val) {
    node *inst = (node *)malloc(sizeof(node));
    if (inst == NULL) {
        printf("[FATAL] Out of memory\n");
        return inst;
    }
    inst->val = val;
    inst->parent = inst->right = inst->left = NULL;
    return inst;
}
void insert(bst *tree, int val) {
    node *z = new_node(val);
    node *y = NULL;
    node *x = tree->root;
    while (x != NULL) {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL) {
        tree->root = z;
    } else if (z->val < y->val) {
        y->left = z;
    } else {
        y->right = z;
    }
    tree->N++;
}
node *search(bst *tree, int val) {
    node *cur = tree->root;
    while (cur != NULL) {
        if (cur->val == val)
            return cur;
        else if (val < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    printf("[ERROR] No node with value %d\n", val);
    return NULL;
}
node *tree_max(node *x) {
    node *cur, *prev;
    cur = prev = x;
    while (cur != NULL) {
        prev = cur;
        cur = cur->right;
    }
    return prev;
}
node *tree_min(node *x) {
    node *cur, *prev;
    cur = prev = x;
    while (cur != NULL) {
        prev = cur;
        cur = cur->left;
    }
    return prev;
}
node *successor(node *x) {
    if (x->right != NULL) {
        return tree_min(x->right);
    }
    node *y = x->parent;
    // Go up until you see a node which is the
    // left child of its parent
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}
node *predecessor(node *x) {
    if (x->left != NULL) {
        return tree_max(x->left);
    }
    node *y = x->parent;
    // Go up until you see a node that is the right
    // child of its parent
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}
void transplant(bst *tree, node *u, node *v) {
    if (u->parent == NULL) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}
void delete_node(bst *tree, node *z) {
    if (z->left == NULL) {
        transplant(tree, z, z->right);
    } else if (z->right == NULL) {
        transplant(tree, z, z->left);
    } else {
        node *y = successor(z);
        if (y->parent != z) {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    tree->N--;
}
void delete_val(bst *tree, int val) {
    node *z = search(tree, val);
    delete_node(tree, z);
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
    printf(" %d\n", cur->val);
    display(cur->left, level + 1);
    display(cur->right, level + 1);
}
int main() {
    bst *tree = new_bst();
    char ch;
    int temp, end = 0;
    node *found;
    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n");
        printf("Enter (1-4), any other character to exit : ");
        scanf(" %c", &ch);
        switch (ch) {
        case '1':
            scanf("%d", &temp);
            insert(tree, temp);
            break;
        case '2':
            scanf("%d", &temp);
            delete_val(tree, temp);
            break;
        case '3':
            scanf("%d", &temp);
            found = search(tree, temp);
            if (found) {
                printf("Value found. %p\n", (void *)found);
            }
            break;
        case '4':
            display(tree->root, 0);
            break;
        default:
            end = 1;
        }
    } while (!end);
    end_bst(tree->root);
    free(tree);
}
