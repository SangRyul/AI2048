#include<stdio.h>
#include<Windows.h>
#include<conio.h>





void PrintUI(void){
	printf("бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс \n");
	printf("бс                                            бс \n");
	printf("бс         <2048>                             бс \n");
	printf("бс                                            бс \n");
	printf("бс         1. HumanRun                        бс \n");
	printf("бс         2. AIRUN                           бс \n");
	printf("бс         3. MAKER                           бс \n");
	printf("бс         4. quit                            бс \n");
	printf("бс                                            бс \n");
	printf("бс                                            бс \n");
	printf("бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс \n");
}

void gotoxy(int  x, int  y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // ┴┬╟е ┬я╛ю┴╓▒т UI

void HumanRunUI(void){
	

}

void AIRunUI(void){

}
