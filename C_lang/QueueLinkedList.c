#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* queue = malloc(sizeof(struct node)); // 꼭 외워 그지새꺄
    queue->next = NULL;
    queue->data = value;

    if (front == NULL) {
        front = queue;
        rear = queue;
    } else {
        rear->next = queue;
        rear = queue;
    }
}

int dequeue() {
    struct node* dequeue = front;
    front = front->next;
    free(dequeue);
}

void display() {
    struct node* display = front;
    while(display != NULL) {
        printf("%d\n", display->data);
        display = display->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}