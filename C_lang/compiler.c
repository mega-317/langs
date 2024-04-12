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
int stack[MAX] ,sp;

int state;
int step;
int inputPop;

int LR_Parser(char* input);

int LR_Parser_Shift(int index, char* input);
int LR_Parser_Reduce(int index, char* input);
void Print(int order, char* input);

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

    step = 1; // 전역변수 값들 초기 세팅
    sp = 0;
    state = 0;
    inputPop = 0;
    stack[sp] = 0;

    printf("%2d. initial  : %d   %s\n", step, stack[sp], input); // initial 단계 출력   
    step += 1;

    int index = 0; // 입력값의 크기 측정
    while( input[index] != '\0' ) {
        index++;
    }

    for(int i=0; i<index; i++) { // 입력값의 크기만큼 반복

        int ti = 0; // 어떤 토큰인지 ti를 index로 사용하여 확인

        while ( token[ti] != '\0' ) {
            if (input[i] == token[ti]) // 어떤 토큰인지 확인
                break;
            else {
                ti++;
            }
        }

        if ( ti == 6 ) { // 입력값이 0~5 범위를 벗어나 해당하는 토큰이 없을 경우
            printf("%2d. invalid token (%c) error\n", step, input[i]);
            return -1;
        }

        if ((action_tbl[state][ti] > 0) && (action_tbl[state][ti] < 999)) { // action_tbl을 참고하여 양수이면서 999가 아닐 경우
            LR_Parser_Shift(ti, input); // shift 연산을 수행한다
        } else if (action_tbl[state][ti] < 0) { // action_tbl을 참고하여 음수이면
            LR_Parser_Reduce(ti, input); // reduce 연산을 수행한다
        } else if (action_tbl[state][ti] == 999) { // action_tbl을 참고하여 999이면
            printf("%2d. accept\n", step); // accept
            return 0;
        } else { // action_tbl을 참고하여 0이면 에러 출력
            printf("%2d. error\n", step);
            return -1;
        }

    }
}

int LR_Parser_Reduce(int index, char* input) { // reduce 연산을 수행하는 함수

    int reduceNum = action_tbl[state][index]; // reduceNum: reduce 몇번 명령인지
    int order = -1 * reduceNum; // order: 몇번째 문법인지
    
    int count = 0; // rhs_len만큼 pop을 하기 위해 pop 개수를 셀 count 선언
    while (count < rhs_len[order]) {
        if (stack[sp] > 11) { //현재 스택 top에 있는 게 문자(토큰)라면
            sp -= 1; // pop
            count += 1; // count 횟수 추가
        } else {
            sp -= 1; // 상태값이면 pop 한 뒤, count는 세지 않음
        }
    }

    sp += 1;
    stack[sp] = lhs[order]; // lhs를 스택에 push

    if (stack[sp] == NT[1]) { // 현재 스택 top에 있는 게 'E'라면
        if (goto_tbl[stack[sp-1]][1] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][1]; //goto_tbl 참고하여 상태값 push
            }
            else {
                printf("%2d. error\n", step);
                return -1;
            }
    } else if (stack[sp] == NT[2]) { // 현재 스택 top에 있는 게 'T'라면
        if (goto_tbl[stack[sp-1]][2] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][2]; //goto_tbl 참고하여 상태값 push
            } else {
                printf("%2d. error\n", step);
                return -1;
            }
    } else if (stack[sp] == NT[3]) { // 현재 스택 top에 있는 게 'F'라면
        if (goto_tbl[stack[sp-1]][3] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][3]; //goto_tbl 참고하여 상태값 push
            } else {
                printf("%2d. error\n", step);
                return -1;
            }
    }

    state = stack[sp]; // 상태값 갱신

    Print(reduceNum, input); // reduce 연산 결과 출력

    if (action_tbl[state][index] < 0) { // 다시 action_tbl 참고
        LR_Parser_Reduce(index, input); // 음수이면 reduce 연산
    } else if ((action_tbl[state][index] > 0) && (action_tbl[state][index] < 999)) {
        LR_Parser_Shift(index, input); // 양수이고, 999가 아니라면 shift 연산
    } else if (action_tbl[state][index] == 999) {
        printf("%2d. accept\n", step); // 999이면 accept
        return 0;
    } else {
        printf("%2d. error\n", step); // 0이면 에러
        return -1;
    }
}

int LR_Parser_Shift(int index, char* input) { // shift 연산을 수행하는 함수

    sp += 1;
    stack[sp] = token[index]; // 스택에 토큰 push

    state = action_tbl[state][index]; // 상태값 갱신

    sp += 1;
    stack[sp] = state; // 스택에 상태값 push

    Print(state, input); // shift 연산 결과 출력
}

void Print(int order, char* input) {

    if(order > 0) { // shift 연산일 경우 입력값이 스택에 push 됐으므로 input의 출력도 하나 줄어들어야 한다
        inputPop++;
    }
    input = &input[inputPop]; // input의 시작점을 한칸 뒤로 미룬다. input의 출력이 하나씩 줄어든다

    if (order > 0) // order가 음수인지 양수인지로 reduce, shift 연산 구분
        printf("%2d.  shift %2d: ", step, order);
    else 
        printf("%2d. reduce %2d: ", step, -order);
        
    for(int i = 0; i<sp + 1; i++) { // 스택에 저장된 내용 출력
        if (stack[i] > 11) { // 최대 상태값을 넘는 값이면 토큰이므로 문자로 출력
            printf("%c", stack[i]);
        } else {
            printf("%d", stack[i]);
        }
    }
    printf("   %s", input); // input 출력
    printf("\n");
    step += 1;
}

