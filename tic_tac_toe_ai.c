#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
// 20195248. 윤수빈. 제출일자 2020.12.19.

char square[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; //global variable
int checkwin(); //승패를 점검하는 함수 
void board(); //게임의 판 
int undo(char, int); //되돌리기 기능 : 무르기 함수 
int player2(int); //al 기능을 하는 함수 
void record(int, int *); //부가기능 : 승패를 기록하는 함수 
int replay(int *); //부가기능 : replay함수 
void load(); //부가기능 
void gotoxy(int, int); //좌표 함수 
void GotoXY(int, int);  //좌표 함수 

int main() 
{
	int player = 1, i, choice; //게임의 플레이어 턴을 구별하기 위해 사용하는 변수 & 반복문 변수 & 입력값을 받아 수를 두는 변수 
	int n=0; //무르기 횟수가 담길 변수 
	int a; //choice computer and haman
	char mark; //수를 둘 때 사용하는 변수 
	int c[9]; //replay와 record함수를 위해 입력된 choice값을 저장하는 배열 
	int *p; //배열의 포인터 
	char ans='y'; //replay여부를 묻기 위해 지정한 변수 
	int l=0; //배열의 도구 
	int v; //승자를 저장하는 변수 
	
	p = c; //배열 c의 포인터 p
		
	//게임 시작 전 게임 모드를 설정할 메뉴 
	printf("\nTic Tac Toc 게임에 오신 것을 환영합니다!");
	
	printf("\n\n\nplayer1 사람- player2 사람 : 1번을 입력하세요   \nplayer1 사람- player2 컴퓨터 : 2번을 입력하세요");
	scanf("%d", &a);
	
	load(); //게임이 어려울 때 설명을 읽는 동안 사용해도 괜찮을 함수같아서 가져왔습니다 
	

	
	
	if(a == 1){ //match human vs match human
		
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        
        if(n<2 && player == 1) //undo mode Conditional
        printf("player 1 posible undo >> 0");
        printf("\nPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);
        c[l] = choice; //배열 c에 choice save 
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
    
    if (i == 1) //승패를 점검하는 함수에서 받아온 값을 화면에 구현 
    {
    	printf("==>\aPlayer %d win ", --player);
        v = player; //승리한 플레이어 저장 -> record에 저장하기 위함 
	}    
    else
    {
		printf("==>\aGame draw");
		v = 0; //무승부일 경우 0을 대입 
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
	
	record(v,p); //record를 실행하는 함수 
	
	printf("\nreplay하시겠습니까? y/n"); //replay를 안내하는 출력문 n을 제외한 값을 입력하면 replay를 시작한다  
    ans = _getch();
    
    if (ans!='n'){
    	replay(p);
	}
    else
    	printf("\nc드라이브에 파일 기록이 저장되었습니다");

    return 0;	
}


void board() //게임의 기본 판  
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


int checkwin() // 게임을 위해 미리정의 된 함수 : 승리자를 결정하는 함수이다  
{
    int i;
    int j;
	
	if (square[0][0] == square[1][1]  && square[0][0] == square[2][2] ) //대각선 줄이 빙고일 때 1을 반환 1 
        return 1;
        
    else if (square[0][2] == square[1][1] && square[0][2] == square[2][0]) //대각선 줄이 빙고일 때 1을 반환 2
        return 1; 
        
    for(i=0; i <=2; i++){ 
    	if(square[i][0] == square[i][1] && square[i][0] == square[i][2]) //가로줄이 빙고일 때 1를 반환  
    	return 1;
    	
    	else if (square[0][i] == square[1][i] && square[0][i] == square[2][i]) //세로줄이 빙고일 때 1를 반환  
    	return 1;
	}
	//for(i=0; i <=2; i++){
	//	if(square[i][0] == mark) 
		//	for(j=0; j <=2; j++)
			//	if(square[i][j] == mark) 
			//		 return 0;
	//} 
	//무승부일 때 0을 반환
	if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' && square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')   
	 	return 0;
    else
        return  - 1;
}

int undo(char mark, int player) 
{
	
	int a;
	
	board();
	
	printf("무르기할 오목번호를 선택하세요");
	scanf("%d", &a);
	
	if(mark == 'X'){ //player1이 둔 수만 무르기 가능 
		
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
        
    else { //숫자인 곳에 무를 경우 다시 턴이 되돌아가며 안내문을 출력한다 
    	player++; 
		printf("not mark"); 
    	Sleep(1000);
    	
	}
    	

	}
	else{
		player++; //plaer2의 수를 무를 경우 다시 턴이 되돌아가며 안내문을 출력 
		printf("not your turn stone");
    	Sleep(1000);
    	
	}
    
	return player;
	
}

int player2(int choice)  
{
	int choice2; // compter player2 choice
	int a[10]; //입력 받은 값을 저장하는 배열  
	int b;
	
	board();
	
	//틱택톡 승리 전략은 밑의 위키를 참고하여 구현하였습니다. 레포트에 링크 걸어두겠습니다 
	//https://ko.wikihow.com/%ED%8B%B1%ED%83%9D%ED%86%A0%EC%97%90%EC%84%9C-%EC%9D%B4%EA%B8%B0%EB%8A%94-%EB%B0%A9%EB%B2%95#.EB.91.90-.EB.B2.88.EC.A7.B8-.EC.88.98.EB.A5.BC-.EB.91.90.EA.B3.A0-.EC.A0.88.EB.8C.80-.EC.A7.80.EC.A7.80-.EC.95.8A.EB.8A.94-.EB.B0.A9.EB.B2.95
	

    if(square[0][0] == square[0][1] && square[0][2] != 'O'  && square[0][2] != 'X' ) //가로줄 방어 & 공격  : 가로줄의 연속된 값이나 양 옆의 값이 체크되어 있을 경우 세줄이 되는 것을 막거나 세줄이 되게 둔다 
    choice2 = 3;																		//그러나 그 곳이 이미 두어져 있을 경우 두지 않는다 
    	
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
    
    else if(square[0][0] == square[1][0] && square[2][0] != 'O'  && square[2][0] != 'X') //세로줄 방어 & 공격 : 세로줄의 연속된 값이나 양 옆의 값이 체크되어 있을 경우 세줄이 되는 것을 막거나 세줄이 되게 둔다 
    choice2 = 7;																			//마찬가지로 이미 두어져 있을 경우 두지 않는다 
    	
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
    
	else if (square[0][0] == square[1][1]) //대각선 줄 방어 & 공격 : 대각선 줄의 양 옆이나 연속된 값이 체크되어 있을 경우 막거나 공격하는 조건문입니다. 
        choice2 = 9;						//중복 방어를 달지 않는 이유는 기본적으로 중앙선점 알고리즘 & 중앙이 선점못할 경우 모퉁이 선점 알고리즘이기 때문입니다 
    
	else if ( square[0][0] == square[2][2])  
		choice2 = 5;
		
	else if(square[1][1] == square[2][2])
		choice2 = 1;
        
    else if (square[0][2] == square[1][1]) //대각선 줄 방어 & 공격  
        choice2 = 7;
    
    else if(square[0][2] == square[2][0])
		choice2 = 5; 
	
	else if(square[1][1] ==  square[2][0])
		choice2 = 3;

	else if(square[1][1] == '5') //중앙 선점 if문  (링크의 위키 참조 : 전략적으로 중앙을 선점할 경우 승리 확률이 커집니다) 
		choice2 = 5;
		
	else if(square[1][1] == 'O') ////중앙을 선점 후 모퉁이 선점 if문 (링크의 위키참조 : 방어를 효과적으로 할 수 있는 전략입니다) 
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
	
	
	
	else if(square[1][1] == 'X') //중앙을 선점 당할 경우 모퉁이 선점 if문 (링크의 위키 참조 : 방어를 효과적으로 할 수 있는 전략입니다) 
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
	else if(square[1][1] == 'X' && square[1][0] == 'O' && square[1][2] == 'O') //oxo일 경우 모퉁이 선점 (링크의 위키 참조 : 이 수가 상대가 둬준다면 컴퓨터가 승리할 수 있는 전략입니다) 
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
	
	else if(square[1][1] == 'X' && square[0][0] == 'O' || square[0][2] == 'O' || square[2][0] == 'O' || square[2][2] == 'O') //상대가 모퉁이 시작일 경우 : 효과적인 방어 전략입니다 
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





int replay(int *p) //replay하는 함수  
{
	int player = 1, i, choice;
	int h[8]; //들어온 포인터를 다시 담아내는 배열 
	int *hp; //그 배열의 포인터 
	int k; //반복문의 도구 
		
	hp = h; 
	
	for(k=0; *(p+k) != NULL; k++){ 
		if(*(p+k)<10) { // 배열의 공간이 남을 경우 빈 공간에 포인트 공간의 주소값이 들어오기 때문에 걸어둔 조건문
			*(hp+k) = *(p+k); 
		}
	
	}
	char mark;
    
        char square1[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //기존에 있는 게임판은 이미 표시가 되어 새로 선언한 게임판의 배열  
        
		for(k=0; *(hp+k) != NULL; k++){	   //for문을 반복하며 받아온 값을 계속 실행
        choice = *(hp+k);
			
	    system("cls"); //적당한 매개변수를 찾기 어려워 함수문 작성 대신 직접 대입한 게임판  
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
        

		if(k%2){ //play가 아닌 루프의 횟수에 따른 표시조건문  
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
        
        Sleep(1000); //눈으로 보기위해 시간지연 함수 선언   
        
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


void record(int v, int *p) //게임의 입력과 승패기록을 보관하기 위한 함수  
{
	FILE *wfp; //포인터 선언  
	wfp = fopen("c:\\playrecord.txt","w"); //파일에 저장한다  
	int j;

	if (v != 0)	//무승부와 승패를 가르는 조건문  
	fprintf(wfp,"Player %d win\n", v);
	else
	fprintf(wfp,"draw game\n");
	
	
	for(j=0; *(p+j) != NULL; j++ ){
    	if(j%2)
		fprintf(wfp,"Player2 %d 입력하였습니다\n",*(p+j));
		else if(*(p+j)<10)
		fprintf(wfp,"Player1 %d 입력하였습니다\n",*(p+j)); 
	}
	
	fclose(wfp);
}



void load() 
{
    int row,col,r,c,q;
    gotoxy(5,10); //로딩위치 설정  
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
    fflush(stdout); //버퍼삭제  
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}











