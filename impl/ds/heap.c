//
// To implement a priority queue using a heap
//
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
typedef struct heap {
    int *tree;
    size_t size;
    size_t capacity;
} heap;
heap *init_heap(size_t capacity) {
    heap *instance = (heap *)malloc(sizeof(heap));
    instance->capacity = capacity;
    instance->tree = (int *)malloc(sizeof(int) * capacity);
    instance->size = 1;
    return instance;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void siftdown(heap *instance, size_t index) {
    if (index >= instance->size)
        return;
    size_t left = 2 * index, right = 2 * index + 1;
    size_t largest = index;
    if (left < instance->size && instance->tree[index] < instance->tree[left]) {
        largest = left;
    }
    if (right < instance->size &&
        instance->tree[largest] < instance->tree[right]) {
        largest = right;
    }
    if (largest != index) {
        swap(&instance->tree[largest], &instance->tree[index]);
        siftdown(instance, largest);
    }
}
void siftup(heap *instance, size_t index) {
    if (index <= 1)
        return;
    size_t parent = index / 2;
    size_t left = 2 * parent, right = 2 * parent + 1;
    size_t largest = parent;
    if (left < instance->size &&
        instance->tree[parent] < instance->tree[left]) {
        largest = left;
    }
    if (right < instance->size &&
        instance->tree[largest] < instance->tree[right]) {
        largest = right;
    }
    if (largest != parent) {
        swap(&instance->tree[largest], &instance->tree[parent]);
        siftup(instance, parent);
    }
}
void end_heap(heap *instance) {
    free(instance->tree);
    free(instance);
}
void insert(heap *instance, int val) {
    if (instance->size == instance->capacity) {
        printf("Heap is full\n");
    } else {
        instance->tree[instance->size] = val;
        instance->size += 1;
        siftup(instance, instance->size - 1);
    }
}
int get_max(heap *instance) {
    if (instance->size == 1) {
        printf("Empty queue\n");
        return 0;
    }
    return instance->tree[1];
}
int pop_max(heap *instance) {
    if (instance->size == 1) {
        printf("Empty queue\n");
        return 0;
    }
    int val = instance->tree[1];
    instance->tree[1] = instance->tree[instance->size - 1];
    instance->size--;
    siftdown(instance, 1);
    return val;
}
void dump(heap *instance) {
    printf("Heap : ");
    for (size_t i = 1; i < instance->size; i++) {
        printf("%d : ", instance->tree[i]);
    }
    printf("\n");
}
int main() {
    int choice, capacity, val;
    int another = 1;
    printf("Enter the capacity of the heap : ");
    scanf("%d", &capacity);
    heap *instance = init_heap(capacity);
    printf("1 and elem for insert, 2 for get_max, 3 for pop_max, any other to "
           "end\n");
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%d", &val);
            insert(instance, val);
            break;
        case 2:
            printf("%d\n", get_max(instance));
            break;
        case 3:
            printf("%d\n", pop_max(instance));
            break;
        default:
            another = 0;
        }
        dump(instance);
    } while (another);
    end_heap(instance);
}
