#include "avl.hpp"
int main() {
    AVL_tree<int> tree;
    char ch;
    int temp, end = 0;
    AVL_node<int> *found;
    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n");
        printf("Enter (1-4), any other character to exit : ");
        scanf(" %c", &ch);
        switch (ch) {
        case '1':
            scanf("%d", &temp);
            tree.insert(temp);
            break;
        case '2':
            scanf("%d", &temp);
            tree.remove(tree.search(temp));
            break;
        case '3':
            scanf("%d", &temp);
            found = tree.search(temp);
            if (found) {
                printf("Value found. %p\n", (void *)found);
            }
            break;
        case '4':
            printf("%s\n", tree.to_string().c_str());
            break;
        default:
            end = 1;
        }
    } while (!end);
}
