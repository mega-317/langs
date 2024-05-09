#include <stdio.h>

int arr[1000000];

int main() {
    int top = -1;

    int num;
    scanf("%d", &num);
    int j, data;
    for(int i=0; i<num; i++) {
        scanf("%d", &j);
        switch (j)
        {
        case 1:
            scanf("%d", &data);
            top ++;
            arr[top] = data;
            break;
        case 2:
            if (top == -1) {
                printf("-1\n");
                break;
            }
            else{
                printf("%d\n", arr[top]);
                top --;
                break;
            }
        case 3:
            printf("%d\n", top+1);
            break;
        case 4:
            if (top == -1) {
                printf("1\n");
            } else {
                printf("0\n");
            }
            break;
        case 5:
            if (top == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", arr[top]);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}