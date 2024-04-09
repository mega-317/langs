#include <stdio.h>

#define SIZE 100

void enqueue(int n);
int dequeue();
void show();
int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    show();

    dequeue();
    dequeue();

    show();
}

void enqueue(int n) {
    if (Front == -1) {
        Front += 1;
        Rear += 1;
    } else {
        Rear += 1;
    }
    inp_arr[Rear] = n;
}

int dequeue() {
    Front += 1;
}

void show() {
    for(int i = Front; i<=Rear; i++) {
        printf("%d\n", inp_arr[i]);
    }
    printf("\n");
}