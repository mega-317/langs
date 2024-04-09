#include <stdio.h>
#include <stdlib.h>

void push(int);
int pop();
void print_s();

typedef struct node {
    int data;
    struct node* next;
} stack;

stack* top = NULL;

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    print_s();

    pop();
    pop();
    print_s();
}

void push(int data) {
    if (top == NULL) {
        stack* node = (stack*)malloc(sizeof(stack));
        node->data = data;
        node->next = NULL;
        top = node;
    } else {
        stack* node = (stack*)malloc(sizeof(stack));
        node->data = data;
        node->next = top;
        top = node;
    }
}

int pop() {
    stack* pop = top;
    top = top->next;
    free(pop);
}

void print_s() {
    stack* print = top;
    while (print != NULL) {
        printf("%d\n", print->data);
        print = print->next;
    }
    printf("\n");
}