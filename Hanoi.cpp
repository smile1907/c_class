#include <stdio.h>
#include <stdlib.h>
typedef struct stack {//������ ������ ������ ����ü
    int data;//�����͸� ����
    struct stack* link;//������ ������ġ ���
}stack;
stack* top; //stack�� �� ����� ������ �� 
stack* Node(); 
void push(int data);//������ �Է� �Լ� ����
int pop();//������ ��� �Լ� ����
int isEmpty();//������ ������� Ȯ�� �Լ� ����
 
int main(void) {
    unsigned scale, ch;
    unsigned from = 1, temp = 2, target = 3, times = 0;
    top = Node();//�ϳ���ž�� ���� ����
    printf("<<�ϳ����� ž>>\n");
    printf("���ݰ��� : ");
    scanf("%d", &scale);
 
 
    while (1) {
        while (scale > 1) {//scale�� 1�� �� ����.
            //from���� temp�� ���� target���� �������� ����
            push(target);push(temp);push(from);
            push(scale);
            scale--;
 
            //temp�� target ���� ���� ��ȯ
            ch = target;
            target = temp;
            temp = ch;
        }
        printf("%d����տ��� %d���������\n", from, target);//������ ¦������ �� ù target�� 2�����, Ȧ������ ���� 3�����
        times++;
        if (!isEmpty()) {//������ ������� ���� �� ����
            //FILO�� ������, scale�� ���� pop
            scale = pop();
            from = pop();temp = pop();target = pop();
            printf("%d����տ��� %d���������\n", from, target);
            times++;
            scale--;
            
            //temp�� from ���� ���� ��ȯ
            ch = from;
            from = temp;
            temp = ch;
 
 
        }
        else {//���� ���� ����.
            break;
        }
    }
    printf("�� ������ Ƚ�� : %d", times);
    return 0;
}
 
stack* Node() {
    stack* p = (stack*)calloc(1, sizeof(stack));//0���� �ʱ�ȭ�ϸ鼭 �޸� �Ҵ�
    //1ũ���� ������ stack�� ũ�⸸ŭ ������ �� �ִ� �޸� ���� �Ҵ�  
    return p;
}
void push(int data) {
    stack* q = Node();//��� ����
    q->data = data;//���� �����͸� ��忡 �Է�
    q->link = top->link;//����� �ּҸ� �ֻ�� �ּҷ� ������
    top->link = q;//�ֻ�� 
}
int pop() {
    stack* q;
    int result;
    q = top->link;//q�� ������ �ֻ��
    result = q->data;//�ֻ���� �����͸� res�� ����
    top->link = q->link;//�ֻ�� �ּ� ������
    free(q);//������ �޸� ����
 
    return result;
}
int isEmpty() {
    return  top->link == NULL;//������ ������� �� 1 ��ȯ
}

