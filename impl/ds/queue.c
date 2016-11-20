#include <malloc.h>
#include <stdio.h>
typedef struct queue {
    int *data;
    int front, rear;
    int size;
} queue;
queue *new_queue(int n) {
    queue *new_queue = (queue *)malloc(sizeof(queue));
    new_queue->size = n;
    new_queue->data = (int *)malloc(sizeof(int) * n);
    new_queue->front = new_queue->rear = -1;
    return new_queue;
}
int is_empty(queue *inst) {
    return inst->front == inst->rear && inst->front == -1;
}
int is_full(queue *inst) {
    return inst->front == (inst->rear + 1) % inst->size;
}
void enqueue(queue *inst, int val) {
    if (is_full(inst)) {
        printf("The queue is full\n");
        return;
    }
    if (inst->front == -1) {
        inst->front = inst->rear = 0;
    } else {
        inst->rear++;
        inst->rear %= inst->size;
    }
    inst->data[inst->rear] = val;
}
int dequeue(queue *inst) {
    if (is_empty(inst)) {
        printf("The queue is empty\n");
        return -1;
    }
    int val = inst->data[inst->front];
    if (inst->front == inst->rear) {
        inst->front = inst->rear = -1;
    } else {
        inst->front = inst->front + 1;
        inst->front %= inst->size;
    }
    return val;
}
int main() {
    queue *inst = new_queue(5);
    int choice, elem, another = 1;
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf(" %d", &elem);
            enqueue(inst, elem);
            break;
        case 2:
            printf("%d\n", dequeue(inst));
            break;
        default:
            another = 0;
        }
        printf("\n");
        for (int i = inst->front; inst->front != -1; i++) {
            i %= inst->size;
            printf("%d : ", inst->data[i]);
            if (i == inst->rear) {
                break;
            }
        }
    } while (another);
}
