#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
// 20195248. ������. �������� 2020.12.19.

char square[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; //global variable
int checkwin(); //���и� �����ϴ� �Լ� 
void board(); //������ �� 
int undo(char, int); //�ǵ����� ��� : ������ �Լ� 
int player2(int); //al ����� �ϴ� �Լ� 
void record(int, int *); //�ΰ���� : ���и� ����ϴ� �Լ� 
int replay(int *); //�ΰ���� : replay�Լ� 
void load(); //�ΰ���� 
void gotoxy(int, int); //��ǥ �Լ� 
void GotoXY(int, int);  //��ǥ �Լ� 

int main() 
{
	int player = 1, i, choice; //������ �÷��̾� ���� �����ϱ� ���� ����ϴ� ���� & �ݺ��� ���� & �Է°��� �޾� ���� �δ� ���� 
	int n=0; //������ Ƚ���� ��� ���� 
	int a; //choice computer and haman
	char mark; //���� �� �� ����ϴ� ���� 
	int c[9]; //replay�� record�Լ��� ���� �Էµ� choice���� �����ϴ� �迭 
	int *p; //�迭�� ������ 
	char ans='y'; //replay���θ� ���� ���� ������ ���� 
	int l=0; //�迭�� ���� 
	int v; //���ڸ� �����ϴ� ���� 
	
	p = c; //�迭 c�� ������ p
		
	//���� ���� �� ���� ��带 ������ �޴� 
	printf("\nTic Tac Toc ���ӿ� ���� ���� ȯ���մϴ�!");
	
	printf("\n\n\nplayer1 ���- player2 ��� : 1���� �Է��ϼ���   \nplayer1 ���- player2 ��ǻ�� : 2���� �Է��ϼ���");
	scanf("%d", &a);
	
	load(); //������ ����� �� ������ �д� ���� ����ص� ������ �Լ����Ƽ� �����Խ��ϴ� 
	

	
	
	if(a == 1){ //match human vs match human
		
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        
        if(n<2 && player == 1) //undo mode Conditional
        printf("player 1 posible undo >> 0");
        printf("\nPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);
        c[l] = choice; //�迭 c�� choice save 
        l++;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[0][0] == '1')
            square[0][0] = mark;
            
        else if (choice == 2 && square[0][1] == '2')
            square[0][1] = mark;
            
        else if (choice == 3 && square[0][2] == '3')
            square[0][2] = mark;
            
        else if (choice == 4 && square[1][0] == '4')
            square[1][0] = mark;
            
        else if (choice == 5 && square[1][1] == '5')
            square[1][1] = mark;
            
        else if (choice == 6 && square[1][2] == '6')
            square[1][2] = mark;
            
        else if (choice == 7 && square[2][0] == '7')
            square[2][0] = mark;
            
        else if (choice == 8 && square[2][1] == '8')
            square[2][1] = mark;
            
        else if (choice == 9 && square[2][2] == '9')
            square[2][2] = mark;
            
        else if (choice == 0){
			n++; //undo count variable
			player = undo(mark,player);
		}

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        
        	 
        i = checkwin();

        player++; //player turn change
    }while (i ==  - 1);
    
    board();
    
    if (i == 1) //���и� �����ϴ� �Լ����� �޾ƿ� ���� ȭ�鿡 ���� 
    {
    	printf("==>\aPlayer %d win ", --player);
        v = player; //�¸��� �÷��̾� ���� -> record�� �����ϱ� ���� 
	}    
    else
    {
		printf("==>\aGame draw");
		v = 0; //���º��� ��� 0�� ���� 
	   }   
	
    getch();
    
	}
	
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	
	

		
	else if(a == 2){ //human vs computer
    
	do
    {
        board();
        player = (player % 2) ? 1 : 2;

        
        if(player == 1) //undo mode Conditional
        {	
        	if(n<2)
        	{
        		printf("player 1 posible undo >> 0");
			}
        printf("\nPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);
    	}
    	else{
    	choice = player2(choice);
		}
		
		c[l] = choice;
		l++;
        
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[0][0] == '1')
            square[0][0] = mark;
            
        else if (choice == 2 && square[0][1] == '2')
            square[0][1] = mark;
            
        else if (choice == 3 && square[0][2] == '3')
            square[0][2] = mark;
            
        else if (choice == 4 && square[1][0] == '4')
            square[1][0] = mark;
            
        else if (choice == 5 && square[1][1] == '5')
            square[1][1] = mark;
            
        else if (choice == 6 && square[1][2] == '6')
            square[1][2] = mark;
            
        else if (choice == 7 && square[2][0] == '7')
            square[2][0] = mark;
            
        else if (choice == 8 && square[2][1] == '8')
            square[2][1] = mark;
            
        else if (choice == 9 && square[2][2] == '9')
            square[2][2] = mark;
            
        else if (choice == 0){
			n++; //undo count variable
			player = undo(mark,player);
		}

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        
        	 
        i = checkwin();

        player++; //player turn change
        
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();
	
	}
	
	record(v,p); //record�� �����ϴ� �Լ� 
	
	printf("\nreplay�Ͻðڽ��ϱ�? y/n"); //replay�� �ȳ��ϴ� ��¹� n�� ������ ���� �Է��ϸ� replay�� �����Ѵ�  
    ans = _getch();
    
    if (ans!='n'){
    	replay(p);
	}
    else
    	printf("\nc����̺꿡 ���� ����� ����Ǿ����ϴ�");

    return 0;	
}


void board() //������ �⺻ ��  
{

	
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[0][0], square[0][1], square[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[1][0], square[1][1], square[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[2][0], square[2][1], square[2][2]);

    printf("     |     |     \n\n");
    
    
}


int checkwin() // ������ ���� �̸����� �� �Լ� : �¸��ڸ� �����ϴ� �Լ��̴�  
{
    int i;
    int j;
	
	if (square[0][0] == square[1][1]  && square[0][0] == square[2][2] ) //�밢�� ���� ������ �� 1�� ��ȯ 1 
        return 1;
        
    else if (square[0][2] == square[1][1] && square[0][2] == square[2][0]) //�밢�� ���� ������ �� 1�� ��ȯ 2
        return 1; 
        
    for(i=0; i <=2; i++){ 
    	if(square[i][0] == square[i][1] && square[i][0] == square[i][2]) //�������� ������ �� 1�� ��ȯ  
    	return 1;
    	
    	else if (square[0][i] == square[1][i] && square[0][i] == square[2][i]) //�������� ������ �� 1�� ��ȯ  
    	return 1;
	}
	//for(i=0; i <=2; i++){
	//	if(square[i][0] == mark) 
		//	for(j=0; j <=2; j++)
			//	if(square[i][j] == mark) 
			//		 return 0;
	//} 
	//���º��� �� 0�� ��ȯ
	if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' && square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')   
	 	return 0;
    else
        return  - 1;
}

int undo(char mark, int player) 
{
	
	int a;
	
	board();
	
	printf("�������� �����ȣ�� �����ϼ���");
	scanf("%d", &a);
	
	if(mark == 'X'){ //player1�� �� ���� ������ ���� 
		
	if(square[0][0] == mark && a == 1)
		square[0][0] = '1';
		
	else if (a == 2 && square[0][1] == mark)
        square[0][1] = '2';
            
    else if (a == 3 && square[0][2] == mark)
        square[0][2] = '3';
            
    else if (a == 4 && square[1][0] == mark)
        square[1][0] = '4';
            
    else if (a == 5 && square[1][1] == mark)
        square[1][1] = '5';
            
    else if (a == 6 && square[1][2] == mark)
        square[1][2] = '6';
            
    else if (a == 7 && square[2][0] == mark)
        square[2][0] = '7';
            
    else if (a == 8 && square[2][1] == mark)
        square[2][1] = '8';
            
    else if (a == 9 && square[2][2] == mark)
        square[2][2] = '9';
        
    else { //������ ���� ���� ��� �ٽ� ���� �ǵ��ư��� �ȳ����� ����Ѵ� 
    	player++; 
		printf("not mark"); 
    	Sleep(1000);
    	
	}
    	

	}
	else{
		player++; //plaer2�� ���� ���� ��� �ٽ� ���� �ǵ��ư��� �ȳ����� ��� 
		printf("not your turn stone");
    	Sleep(1000);
    	
	}
    
	return player;
	
}

int player2(int choice)  
{
	int choice2; // compter player2 choice
	int a[10]; //�Է� ���� ���� �����ϴ� �迭  
	int b;
	
	board();
	
	//ƽ���� �¸� ������ ���� ��Ű�� �����Ͽ� �����Ͽ����ϴ�. ����Ʈ�� ��ũ �ɾ�ΰڽ��ϴ� 
	//https://ko.wikihow.com/%ED%8B%B1%ED%83%9D%ED%86%A0%EC%97%90%EC%84%9C-%EC%9D%B4%EA%B8%B0%EB%8A%94-%EB%B0%A9%EB%B2%95#.EB.91.90-.EB.B2.88.EC.A7.B8-.EC.88.98.EB.A5.BC-.EB.91.90.EA.B3.A0-.EC.A0.88.EB.8C.80-.EC.A7.80.EC.A7.80-.EC.95.8A.EB.8A.94-.EB.B0.A9.EB.B2.95
	

    if(square[0][0] == square[0][1] && square[0][2] != 'O'  && square[0][2] != 'X' ) //������ ��� & ����  : �������� ���ӵ� ���̳� �� ���� ���� üũ�Ǿ� ���� ��� ������ �Ǵ� ���� ���ų� ������ �ǰ� �д� 
    choice2 = 3;																		//�׷��� �� ���� �̹� �ξ��� ���� ��� ���� �ʴ´� 
    	
    else if(square[0][0] == square[0][2] && square[0][1] != 'O'  && square[0][1] != 'X')  
    choice2 = 2;
    	
    else if(square[0][1] == square[0][2] && square[0][0] != 'O'  && square[0][0] != 'X')
    choice2 = 1;
    	
    else if (square[1][0] == square[1][1] && square[1][2] != 'O' && square[1][2] != 'X') 
    choice2 = 6;
    
    else if(square[1][0] == square[1][2] && square[1][1] != 'O'  && square[1][1] != 'X')
    choice2 = 5;
    	
    else if(square[1][1] == square[1][2] && square[1][0] != 'O'  && square[1][0] != 'X')
    choice2 = 4;
    
    else if (square[2][0] == square[2][1] && square[2][2] != 'O'  && square[2][2] != 'X') 
    choice2 = 9;
    
    else if(square[2][0] == square[2][2] && square[2][1] != 'O'  && square[2][1] != 'X')
    choice2 = 8;
    	
    else if(square[2][1] == square[2][2] && square[2][0] != 'O' && square[2][0] != 'X') 
    choice2 = 7;
    
    else if(square[0][0] == square[1][0] && square[2][0] != 'O'  && square[2][0] != 'X') //������ ��� & ���� : �������� ���ӵ� ���̳� �� ���� ���� üũ�Ǿ� ���� ��� ������ �Ǵ� ���� ���ų� ������ �ǰ� �д� 
    choice2 = 7;																			//���������� �̹� �ξ��� ���� ��� ���� �ʴ´� 
    	
    else if(square[0][0] == square[2][0] && square[1][0] != 'O'  && square[1][0] != 'X')
    choice2 = 4;
    	
    else if(square[1][0] == square[2][0] && square[0][0] != 'O'  && square[0][0] != 'X')
    choice2 = 1;
    
    else if(square[0][1] == square[1][1] && square[2][1] != 'O'  && square[2][1] != 'X') 
    choice2 = 8;
    	
    else if(square[0][1] == square[2][1] && square[2][1] != 'O'  && square[2][1] != 'X')
    choice2 = 5;
    	
    else if(square[1][1] == square[2][1] && square[0][1] != 'O'  && square[0][1] != 'X')
    choice2 = 2;
    
    else if(square[0][2] == square[1][2] && square[2][2] != 'O'  && square[2][2] != 'X') 
    choice2 = 9;
    	
    else if(square[0][2] == square[2][2] && square[1][2] != 'O' && square[1][2] != 'X')
    choice2 = 6;
    	
    else if(square[1][2] == square[2][2] && square[0][2] != 'O' && square[0][2] != 'X')	
    choice2 = 3;
    
	else if (square[0][0] == square[1][1]) //�밢�� �� ��� & ���� : �밢�� ���� �� ���̳� ���ӵ� ���� üũ�Ǿ� ���� ��� ���ų� �����ϴ� ���ǹ��Դϴ�. 
        choice2 = 9;						//�ߺ� �� ���� �ʴ� ������ �⺻������ �߾Ӽ��� �˰��� & �߾��� �������� ��� ������ ���� �˰����̱� �����Դϴ� 
    
	else if ( square[0][0] == square[2][2])  
		choice2 = 5;
		
	else if(square[1][1] == square[2][2])
		choice2 = 1;
        
    else if (square[0][2] == square[1][1]) //�밢�� �� ��� & ����  
        choice2 = 7;
    
    else if(square[0][2] == square[2][0])
		choice2 = 5; 
	
	else if(square[1][1] ==  square[2][0])
		choice2 = 3;

	else if(square[1][1] == '5') //�߾� ���� if��  (��ũ�� ��Ű ���� : ���������� �߾��� ������ ��� �¸� Ȯ���� Ŀ���ϴ�) 
		choice2 = 5;
		
	else if(square[1][1] == 'O') ////�߾��� ���� �� ������ ���� if�� (��ũ�� ��Ű���� : �� ȿ�������� �� �� �ִ� �����Դϴ�) 
	{
		if(square[0][0] == '1')
		choice2 = 1;
		
		else if(square[0][2] == '3')
		choice2 = 3;
		
		else if(square[2][0] == '7')
		choice2 = 7;
		
		else 
		choice2 = 9;
	}
	
	
	
	else if(square[1][1] == 'X') //�߾��� ���� ���� ��� ������ ���� if�� (��ũ�� ��Ű ���� : �� ȿ�������� �� �� �ִ� �����Դϴ�) 
	{
		if(square[0][0] == '1')
		choice2 = 1;
		
		else if(square[0][2] == '3')
		choice2 = 3;
		
		else if(square[2][0] == '7')
		choice2 = 7;
		
		else 
		choice2 = 9;
	}
	else if(square[1][1] == 'X' && square[1][0] == 'O' && square[1][2] == 'O') //oxo�� ��� ������ ���� (��ũ�� ��Ű ���� : �� ���� ��밡 ���شٸ� ��ǻ�Ͱ� �¸��� �� �ִ� �����Դϴ�) 
	{	
		if(square[0][0] == '1')
		choice2 = 1;
		
		else if(square[0][2] == '3')
		choice2 = 3;
		
		else if(square[2][0] == '7')
		choice2 = 7;
		
		else 
		choice2 = 9;
	}
	
	else if(square[1][1] == 'X' && square[0][0] == 'O' || square[0][2] == 'O' || square[2][0] == 'O' || square[2][2] == 'O') //��밡 ������ ������ ��� : ȿ������ ��� �����Դϴ� 
	{	
		if(square[1][0] == '4')
		choice2 = 4;
		
		else if(square[0][1] == '2')
		choice2 = 2;
		
		else if(square[1][2] == '6')
		choice2 = 6;
		
		else 
		choice2 = 8;
	}
	

	//printf("%d", choice2);
	//Sleep(2000);
	
	return choice2;
}





int replay(int *p) //replay�ϴ� �Լ�  
{
	int player = 1, i, choice;
	int h[8]; //���� �����͸� �ٽ� ��Ƴ��� �迭 
	int *hp; //�� �迭�� ������ 
	int k; //�ݺ����� ���� 
		
	hp = h; 
	
	for(k=0; *(p+k) != NULL; k++){ 
		if(*(p+k)<10) { // �迭�� ������ ���� ��� �� ������ ����Ʈ ������ �ּҰ��� ������ ������ �ɾ�� ���ǹ�
			*(hp+k) = *(p+k); 
		}
	
	}
	char mark;
    
        char square1[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //������ �ִ� �������� �̹� ǥ�ð� �Ǿ� ���� ������ �������� �迭  
        
		for(k=0; *(hp+k) != NULL; k++){	   //for���� �ݺ��ϸ� �޾ƿ� ���� ��� ����
        choice = *(hp+k);
			
	    system("cls"); //������ �Ű������� ã�� ����� �Լ��� �ۼ� ��� ���� ������ ������  
    	printf("\n\n\tTic Tac Toe\n\n");

    	printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    	printf("     |     |     \n");
    	printf("  %c  |  %c  |  %c \n", square1[1], square1[2], square1[3]);

    	printf("_____|_____|_____\n");
    	printf("     |     |     \n");

    	printf("  %c  |  %c  |  %c \n", square1[4], square1[5], square1[6]);

    	printf("_____|_____|_____\n");
    	printf("     |     |     \n");

    	printf("  %c  |  %c  |  %c \n", square1[7], square1[8], square1[9]);

    	printf("     |     |     \n\n");
        

		if(k%2){ //play�� �ƴ� ������ Ƚ���� ���� ǥ�����ǹ�  
			mark = 'X'; 
		}
		
		else {
			mark = 'O';
		}
		
		
        if (choice == 1) 
            square1[1] = mark;
            
        else if (choice == 2 )
            square1[2] = mark;
            
        else if (choice == 3 )
            square1[3] = mark;
            
        else if (choice == 4 )
            square1[4] = mark;
            
        else if (choice == 5 )
            square1[5] = mark;
            
        else if (choice == 6 )
            square1[6] = mark;
            
        else if (choice == 7 )
            square1[7] = mark;
            
        else if (choice == 8 )
            square1[8] = mark;
            
        else if (choice == 9)
            square1[9] = mark;
            
        else
        {
            printf("replay end!");

            getch();
        }
        
        Sleep(1000); //������ �������� �ð����� �Լ� ����   
        
		}
    
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square1[1], square1[2], square1[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square1[4], square1[5], square1[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square1[7], square1[8], square1[9]);

    printf("     |     |     \n\n");
    

    getch();
	
}


void record(int v, int *p) //������ �Է°� ���б���� �����ϱ� ���� �Լ�  
{
	FILE *wfp; //������ ����  
	wfp = fopen("c:\\playrecord.txt","w"); //���Ͽ� �����Ѵ�  
	int j;

	if (v != 0)	//���ºο� ���и� ������ ���ǹ�  
	fprintf(wfp,"Player %d win\n", v);
	else
	fprintf(wfp,"draw game\n");
	
	
	for(j=0; *(p+j) != NULL; j++ ){
    	if(j%2)
		fprintf(wfp,"Player2 %d �Է��Ͽ����ϴ�\n",*(p+j));
		else if(*(p+j)<10)
		fprintf(wfp,"Player1 %d �Է��Ͽ����ϴ�\n",*(p+j)); 
	}
	
	fclose(wfp);
}



void load() 
{
    int row,col,r,c,q;
    gotoxy(5,10); //�ε���ġ ����  
    printf("loading...");
    gotoxy(13,10);
    for(r=1; r<=30; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("."); 
    }

    getch();
}


void gotoxy(int x, int y) //call by value
{

    COORD coord;

    coord.X = x;
 
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout); //���ۻ���  
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}











