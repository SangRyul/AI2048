#include<stdio.h>
#include<Windows.h>
#include<conio.h>

#define RowNumber 4
#define ColNumber 4



void PrintUI(void){
	printf("������������������������� \n");
	printf("��                                            �� \n");
	printf("��         <2048>                             �� \n");
	printf("��                                            �� \n");
	printf("��         1. HumanRun                        �� \n");
	printf("��         2. AIRUN                           �� \n");
	printf("��         3. MAKER                           �� \n");
	printf("��         4. quit                            �� \n");
	printf("��                                            �� \n");
	printf("��                                            �� \n");
	printf("������������������������� \n");
}

void gotoxy(int  x, int  y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // ��ǥ ����ֱ� UI



void AIRunUI(void){

}


