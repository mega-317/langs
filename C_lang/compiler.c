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

    step = 1; // �������� ���� �ʱ� ����
    sp = 0;
    state = 0;
    inputPop = 0;
    stack[sp] = 0;

    printf("%2d. initial  : %d   %s\n", step, stack[sp], input); // initial �ܰ� ���   
    step += 1;

    int index = 0; // �Է°��� ũ�� ����
    while( input[index] != '\0' ) {
        index++;
    }

    for(int i=0; i<index; i++) { // �Է°��� ũ�⸸ŭ �ݺ�

        int ti = 0; // � ��ū���� ti�� index�� ����Ͽ� Ȯ��

        while ( token[ti] != '\0' ) {
            if (input[i] == token[ti]) // � ��ū���� Ȯ��
                break;
            else {
                ti++;
            }
        }

        if ( ti == 6 ) { // �Է°��� 0~5 ������ ��� �ش��ϴ� ��ū�� ���� ���
            printf("%2d. invalid token (%c) error\n", step, input[i]);
            return -1;
        }

        if ((action_tbl[state][ti] > 0) && (action_tbl[state][ti] < 999)) { // action_tbl�� �����Ͽ� ����̸鼭 999�� �ƴ� ���
            LR_Parser_Shift(ti, input); // shift ������ �����Ѵ�
        } else if (action_tbl[state][ti] < 0) { // action_tbl�� �����Ͽ� �����̸�
            LR_Parser_Reduce(ti, input); // reduce ������ �����Ѵ�
        } else if (action_tbl[state][ti] == 999) { // action_tbl�� �����Ͽ� 999�̸�
            printf("%2d. accept\n", step); // accept
            return 0;
        } else { // action_tbl�� �����Ͽ� 0�̸� ���� ���
            printf("%2d. error\n", step);
            return -1;
        }

    }
}

int LR_Parser_Reduce(int index, char* input) { // reduce ������ �����ϴ� �Լ�

    int reduceNum = action_tbl[state][index]; // reduceNum: reduce ��� �������
    int order = -1 * reduceNum; // order: ���° ��������
    
    int count = 0; // rhs_len��ŭ pop�� �ϱ� ���� pop ������ �� count ����
    while (count < rhs_len[order]) {
        if (stack[sp] > 11) { //���� ���� top�� �ִ� �� ����(��ū)���
            sp -= 1; // pop
            count += 1; // count Ƚ�� �߰�
        } else {
            sp -= 1; // ���°��̸� pop �� ��, count�� ���� ����
        }
    }

    sp += 1;
    stack[sp] = lhs[order]; // lhs�� ���ÿ� push

    if (stack[sp] == NT[1]) { // ���� ���� top�� �ִ� �� 'E'���
        if (goto_tbl[stack[sp-1]][1] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][1]; //goto_tbl �����Ͽ� ���°� push
            }
            else {
                printf("%2d. error\n", step);
                return -1;
            }
    } else if (stack[sp] == NT[2]) { // ���� ���� top�� �ִ� �� 'T'���
        if (goto_tbl[stack[sp-1]][2] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][2]; //goto_tbl �����Ͽ� ���°� push
            } else {
                printf("%2d. error\n", step);
                return -1;
            }
    } else if (stack[sp] == NT[3]) { // ���� ���� top�� �ִ� �� 'F'���
        if (goto_tbl[stack[sp-1]][3] != 0) {
                sp += 1;
                stack[sp] = goto_tbl[stack[sp-2]][3]; //goto_tbl �����Ͽ� ���°� push
            } else {
                printf("%2d. error\n", step);
                return -1;
            }
    }

    state = stack[sp]; // ���°� ����

    Print(reduceNum, input); // reduce ���� ��� ���

    if (action_tbl[state][index] < 0) { // �ٽ� action_tbl ����
        LR_Parser_Reduce(index, input); // �����̸� reduce ����
    } else if ((action_tbl[state][index] > 0) && (action_tbl[state][index] < 999)) {
        LR_Parser_Shift(index, input); // ����̰�, 999�� �ƴ϶�� shift ����
    } else if (action_tbl[state][index] == 999) {
        printf("%2d. accept\n", step); // 999�̸� accept
        return 0;
    } else {
        printf("%2d. error\n", step); // 0�̸� ����
        return -1;
    }
}

int LR_Parser_Shift(int index, char* input) { // shift ������ �����ϴ� �Լ�

    sp += 1;
    stack[sp] = token[index]; // ���ÿ� ��ū push

    state = action_tbl[state][index]; // ���°� ����

    sp += 1;
    stack[sp] = state; // ���ÿ� ���°� push

    Print(state, input); // shift ���� ��� ���
}

void Print(int order, char* input) {

    if(order > 0) { // shift ������ ��� �Է°��� ���ÿ� push �����Ƿ� input�� ��µ� �ϳ� �پ���� �Ѵ�
        inputPop++;
    }
    input = &input[inputPop]; // input�� �������� ��ĭ �ڷ� �̷��. input�� ����� �ϳ��� �پ���

    if (order > 0) // order�� �������� ��������� reduce, shift ���� ����
        printf("%2d.  shift %2d: ", step, order);
    else 
        printf("%2d. reduce %2d: ", step, -order);
        
    for(int i = 0; i<sp + 1; i++) { // ���ÿ� ����� ���� ���
        if (stack[i] > 11) { // �ִ� ���°��� �Ѵ� ���̸� ��ū�̹Ƿ� ���ڷ� ���
            printf("%c", stack[i]);
        } else {
            printf("%d", stack[i]);
        }
    }
    printf("   %s", input); // input ���
    printf("\n");
    step += 1;
}

