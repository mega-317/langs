#include <stdio.h>
#include <string.h>

#define MAX 100

int action_tbl[12][6] = {
    { 5, 0, 0, 4, 0, 0 },     
    { 0, 6, 0, 0, 0, 999 },   
    { 0, -2, 7, 0, -2, -2 },
    { 0, -4, -4, 0, -4, -4 }, 
    { 5, 0, 0, 4, 0, 0 },     
    { 0, -6, -6, 0, -6, -6 },
    { 5, 0, 0, 4, 0, 0 },     
    { 5, 0, 0, 4, 0, 0 },     
    { 0, 6, 0, 0, 11, 0 },
    { 0, -1, 7, 0, -1, -1 },  
    { 0, -3, -3, 0, -3, -3 }, 
    { 0, -5, -5, 0, -5, -5 }
};

int goto_tbl[12][4] = {
    { 0, 1, 2, 3 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 8, 2, 3 },
    { 0, 0, 0, 0 },
    { 0, 0, 9, 3 },
    { 0, 0, 0, 10 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};

char lhs[] = { ' ', 'E', 'E', 'T', 'T', 'F', 'F' };
int rhs_len[] = { 0, 3, 1, 3, 1, 3, 1 }; 

char token[] = { 'd', '+', '*', '(', ')', '$' };
char NT[] = { ' ', 'E', 'T', 'F' };
int stack[MAX];
int sp;
int state;
int step;
int inputPop;

int LR_Parser(char* input);

int LR_Parser_Shift(char token, int* state, int* sp, int num, char* input);
int LR_Parser_Reduce(char token, int* state, int* sp, int num, char* input);
void Print(int* sp, char* op, int num, char* input);

int main() {
    char input[MAX];
    while(1) {
        printf("\nInput: ");
        scanf("%s", input);
        
        if (input[0] == '$')
            break;
        LR_Parser(input);
    }
    return 0;
}

int LR_Parser(char* input) {
    step = 1;
    sp = 0;
    state = 0;
    inputPop = 0;
    stack[sp] = 0;

    printf("(%d) initial : %d %s\n", step, stack[sp], input);
    step += 1;

    char *string = NULL; // string 포인터에 입력값 지정
    string = input;
    if (string == NULL) { // 에러 처리
        printf("error\n");
        return -1;
    }

    int index = 0; // 입력값 하나씩 꺼내는 거 테스트
    while( string[index] != '\0' ) {
        index++;
    }

    for(int i=0; i<index; i++) { // 입력값의 개수만큼 반복

        int j = 0; // 어떤 토큰인지 j로 식별

        while ( token[j] != '\0' ) {
            if (string[i] == token[j])
                break;
            else {
                j++;
            }
        }

        if ( j == 6 ) { // 입력값이 토큰이 아닐 경우
            printf("(%d) invalid token (%c) error\n", step, string[i]);
            return -1;
        }

        if ((action_tbl[state][j] > 0) && (action_tbl[state][j] < 20)) {
            LR_Parser_Shift(string[i], &state, &sp, j, input);
        } else if (action_tbl[state][j] < 0) {
            LR_Parser_Reduce(string[i], &state, &sp, j, input);
        } else if (action_tbl[state][j] == 999) {
            printf("(%d) accept\n", step);
            return 0;
        } else {
            printf("(%d) error\n", step);
            return -1;
        }

    }
}

int LR_Parser_Reduce(char token, int* state, int* sp, int num, char* input) {

    int* state_1 = state;
    int* sp_1 = sp;

    int order = -1 * (action_tbl[*state_1][num]); // order: reduce 몇번 명령인지
    
    int count = 0;
    while (count < rhs_len[order]) {
        if (stack[*sp_1] > 11) {
            *sp_1 -= 1;
            count += 1;
        } else {
            *sp_1 -= 1;
        }
    }
    *sp_1 += 1; // ** 포인터이기 때문에 *sp_1++ 를 하면 안된다

    stack[*sp_1] = lhs[order];

    switch(stack[*sp_1]) {
        case 'E':
            if (goto_tbl[stack[*sp_1-1]][1] != 0) {
                *sp_1 += 1;
                stack[*sp_1] = goto_tbl[stack[*sp_1-2]][1];
                break;
            }
            else {
                printf("(%d) error\n", step);
                return -1;
            }
        case 'T':
            if (goto_tbl[stack[*sp_1-1]][2] != 0) {
                *sp_1 += 1;
                stack[*sp_1] = goto_tbl[stack[*sp_1-2]][2];
                break;
            } else {
                printf("(%d) error\n", step);
                return -1;
            }
        case 'F':
            if (goto_tbl[stack[*sp_1-1]][3] != 0) {
                *sp_1 += 1;
                stack[*sp_1] = goto_tbl[stack[*sp_1-2]][3];
                break;
            } else {
                printf("(%d) error\n", step);
                return -1;
            }
    }

    *state_1 = stack[*sp_1]; // 상태값 갱신

    Print(sp_1, "reduce", order, input);

    if (action_tbl[*state_1][num] < 0) {
        LR_Parser_Reduce(token, state_1, sp_1, num, input);
    } else if ((action_tbl[*state_1][num] > 0) && (action_tbl[*state_1][num] < 999)) {
        LR_Parser_Shift(token, state_1, sp_1, num, input);
    } else if (action_tbl[*state_1][num] == 999) {
        printf("(%d) accept\n", step);
    } else {
        printf("(%d) error\n", step);
        return -1;
    }
}

int LR_Parser_Shift(char token, int* state, int* sp, int num, char* input) {

    int* state_1 = state;
    int* sp_1 = sp;

    *sp_1 += 1; // push 하기 위해 sp 1 증가
    stack[*sp_1] = token; // 스택에 토큰 추가
    *state_1 = action_tbl[*state_1][num]; // 상태값 갱신
    *sp_1 += 1;
    stack[*sp_1] = *state_1;

    Print(sp_1, "shift", *state_1, input);
}

void Print(int* sp, char* op, int num, char* input) {
    if(strcmp(op, "shift") == 0) {
        inputPop++;
    }

    input = &input[inputPop];
    
    printf("(%d) %s %d: ", step, op, num);
    for(int i = 0; i<*sp + 1; i++) {
        if (stack[i] > 11) {
            printf("%c", stack[i]);
        } else {
            printf("%d", stack[i]);
        }
    }
    printf(" %s", input);
    printf("\n");
    step += 1;
}

