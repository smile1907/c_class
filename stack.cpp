#include<stdio.h>
#include<stdlib.h>
 
#define SIZE 10
 
//스택 구조체
typedef struct stack {
    int arr[SIZE];
    int top;
};
 
void stack_init(stack *pstack) { //pstack이라는 주소값을 받아옴 , 스택의 기본값  -1로 지정  
    pstack -> top = -1;
}
 
//스택이 비어있는지 체크
bool isEmpty(stack *pstack) { //pstack이라는 주소값을 받아옴, 스택값 -1일 경우 비어있다 
    if (pstack->top == -1) {
        return true;	
    }
        return false;
}
 
//삽입
void push(stack *pstack, int data) { //pstack이라는 주소값에 data값을 대입한다  
    pstack->top += 1; //top값에 1을 더한다  
    pstack->arr[pstack->top] = data; //stack이 들어 있는 배열에 data값을 넣는다  
}
 
//삭제
int pop(stack *pstack){
    if (isEmpty(pstack) == true) {
        printf("stack is empty!"); //스택값이 비었을 경우 문자를 출력한다  
    }else{
        printf("pop : %d\n", pstack->arr[pstack->top]); //빼내는 값을 표기하고 배열의 개수를 줄인다  
        pstack->arr[pstack->top--];
    }
}




int main(){
	stack stack;
    stack_init(&stack);
 
  	int n=0, from=1, by=2, to=3; 
  
  
	printf("원반의 수 ");
	scanf("%d",&n);
 
  while (1){
        while (n > 1){
            push(&stack, to);    // 인자리스트 푸쉬
            push(&stack, by);
            push(&stack, from);
            push(&stack, n);
            n--;        // 인자리스트 변경 1
            push(&stack,to);    // to 와 by를 교환하기 위해 임시로 저장
            to = by;
            pop(&stack);
            by = stack.arr[stack.top];
        }

        printf("\nMove disk %d from %d to %d",n, from, to);

        if (!isEmpty(&stack)){
            pop(&stack);
			n = stack.arr[stack.top];
			pop(&stack);
            from = stack.arr[stack.top];
            pop(&stack);
            by = stack.arr[stack.top];
            pop(&stack);
            to = stack.arr[stack.top];

        printf("\nMove disk %d from %d to %d",n, from, to);

            n--;        // 인자리스트 변경 2
            push(&stack, from);
            from = by;
            pop(&stack);
            by = stack.arr[stack.top];
        }
        else{
            break;
        }
    }
  
}





