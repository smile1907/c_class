#include<stdio.h>
#include<stdlib.h>
 
#define SIZE 10
 
//���� ����ü
typedef struct stack {
    int arr[SIZE];
    int top;
};
 
void stack_init(stack *pstack) { //pstack�̶�� �ּҰ��� �޾ƿ� , ������ �⺻��  -1�� ����  
    pstack -> top = -1;
}
 
//������ ����ִ��� üũ
bool isEmpty(stack *pstack) { //pstack�̶�� �ּҰ��� �޾ƿ�, ���ð� -1�� ��� ����ִ� 
    if (pstack->top == -1) {
        return true;	
    }
        return false;
}
 
//����
void push(stack *pstack, int data) { //pstack�̶�� �ּҰ��� data���� �����Ѵ�  
    pstack->top += 1; //top���� 1�� ���Ѵ�  
    pstack->arr[pstack->top] = data; //stack�� ��� �ִ� �迭�� data���� �ִ´�  
}
 
//����
int pop(stack *pstack){
    if (isEmpty(pstack) == true) {
        printf("stack is empty!"); //���ð��� ����� ��� ���ڸ� ����Ѵ�  
    }else{
        printf("pop : %d\n", pstack->arr[pstack->top]); //������ ���� ǥ���ϰ� �迭�� ������ ���δ�  
        pstack->arr[pstack->top--];
    }
}




int main(){
	stack stack;
    stack_init(&stack);
 
  	int n=0, from=1, by=2, to=3; 
  
  
	printf("������ �� ");
	scanf("%d",&n);
 
  while (1){
        while (n > 1){
            push(&stack, to);    // ���ڸ���Ʈ Ǫ��
            push(&stack, by);
            push(&stack, from);
            push(&stack, n);
            n--;        // ���ڸ���Ʈ ���� 1
            push(&stack,to);    // to �� by�� ��ȯ�ϱ� ���� �ӽ÷� ����
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

            n--;        // ���ڸ���Ʈ ���� 2
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





