#include <stdio.h>
#include <stdlib.h>
typedef struct stack {//스택을 구현한 간단한 구조체
    int data;//데이터를 저장
    struct stack* link;//스택의 저장위치 기록
}stack;
stack* top; //stack의 윗 상단의 포인터 값 
stack* Node(); 
void push(int data);//데이터 입력 함수 선언
int pop();//데이터 출력 함수 선언
int isEmpty();//스택이 비었는지 확인 함수 선언
 
int main(void) {
    unsigned scale, ch;
    unsigned from = 1, temp = 2, target = 3, times = 0;
    top = Node();//하노이탑을 담을 스택
    printf("<<하노이의 탑>>\n");
    printf("원반개수 : ");
    scanf("%d", &scale);
 
 
    while (1) {
        while (scale > 1) {//scale이 1일 때 종료.
            //from에서 temp를 거쳐 target으로 가기위한 과정
            push(target);push(temp);push(from);
            push(scale);
            scale--;
 
            //temp와 target 서로 역할 교환
            ch = target;
            target = temp;
            temp = ch;
        }
        printf("%d번기둥에서 %d번기둥으로\n", from, target);//원반이 짝수개일 때 첫 target은 2번기둥, 홀수개일 때는 3번기둥
        times++;
        if (!isEmpty()) {//스택이 비어있지 않을 때 실행
            //FILO기 때문에, scale을 먼저 pop
            scale = pop();
            from = pop();temp = pop();target = pop();
            printf("%d번기둥에서 %d번기둥으로\n", from, target);
            times++;
            scale--;
            
            //temp와 from 서로 역할 교환
            ch = from;
            from = temp;
            temp = ch;
 
 
        }
        else {//스택 비우면 종료.
            break;
        }
    }
    printf("총 움직임 횟수 : %d", times);
    return 0;
}
 
stack* Node() {
    stack* p = (stack*)calloc(1, sizeof(stack));//0으로 초기화하면서 메모리 할당
    //1크기의 변수를 stack의 크기만큼 저장할 수 있는 메모리 공간 할당  
    return p;
}
void push(int data) {
    stack* q = Node();//노드 생성
    q->data = data;//들어온 데이터를 노드에 입력
    q->link = top->link;//노드의 주소를 최상단 주소로 재지정
    top->link = q;//최상단 
}
int pop() {
    stack* q;
    int result;
    q = top->link;//q는 스택의 최상단
    result = q->data;//최상단의 데이터를 res에 저장
    top->link = q->link;//최상단 주소 재지정
    free(q);//무쓸모 메모리 해제
 
    return result;
}
int isEmpty() {
    return  top->link == NULL;//스택이 비어있을 때 1 반환
}

