#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

int isEmpty(node* top) {
    return (top == NULL);
}

void push(node** top, int data, int* count) {
    node* new = NULL;
    new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("error\n");
        return;
    }

    new->data = data;
    new->next = *top;
    *top = new;
    *count = *count + 1;
}

void pop(node** top, int* count) {
    if (isEmpty(*top)) {
        printf("-1\n");
    } else {
        node* temp = *top;
       *top = temp->next;
        printf("%d\n", temp->data);
        *count = *count - 1;
        free(temp);
    }
}

void printTop(node** top) {
    if (isEmpty(*top)) {
        printf("-1\n");
    } else {
        node* temp = *top;
        printf("%d\n", temp->data);
    }
}

int main() {
    int num, order, data;
    int count = 0;
    scanf("%d\n", &num);

    node* top = NULL;

    for (int i=0; i<num; i++) {
        scanf("%d", &order);

        switch (order)
        {
        case 1:
            scanf("%d", &data);
            push(&top, data, &count);
            break;
        case 2:
            pop(&top, &count);
            break;
        case 3:
            printf("%d\n", count);
            break;
        case 4:
            if (top == NULL) {
                printf("1\n");
            } else {
                printf("0\n");
            }
            break;
        case 5:
            printTop(&top);
            break;    
        default:
            break;
        }
    }
}