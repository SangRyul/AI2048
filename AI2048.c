#pragma warning(disable:4996)
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>



#include"UI.h"
#define RowNumber 4
#define ColNumber 4

int Board[RowNumber][ColNumber] = { 0, };


//test 조작
int MemoryBoard[RowNumber][ColNumber]; // 움직임의 이동을 파악하기 위한 메모제이션
int Randomtable[10] = { 2, 2, 2, 2, 2, 4, 2, 2, 2, 2 };
void PrintBoard(void){

	for (int i = 0; i < RowNumber; i++){


		for (int j = 0; j < ColNumber; j++){
			for (int k = 1; k <= 12; k++){
				if (Board[i][j] == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else if (Board[i][j] == (int)pow(2, k)) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k+1);
				}
			}
			printf("%4d", Board[i][j]);
		}
		printf("\n");
		printf("\n");
	
	}
}


void InitialNumber(void){
	
	int a = rand() % 4;
	int b = rand() % 4;
	int ran = rand() % 10;

	Board[a][b] = Randomtable[ran];

}
void RandomNumber(void){

	int a = rand() % 4;
	int b = rand() % 4;
	int ran = rand() % 10;

	if (Board[a][b] == 0){
		Board[a][b] = Randomtable[ran];
	}
	else{
		RandomNumber();
	}

}
int UpKey(void){


	int movement = 0;
	for (int i = 0; i < RowNumber; i++) {
		for (int j = 0; j < ColNumber; j++) {
			MemoryBoard[i][j] = Board[i][j];
		}
	}

	for (int i = 0; i < ColNumber; i++) {

		for (int j = RowNumber - 1; j >0; j--) {

			if ((Board[j][i] != Board[j-1][i]) && (Board[j-1][i] != 0)) {
				;
			}
			else if (Board[j-1][i] == 0) {
				Board[j-1][i] = Board[j][i];
				Board[j][i] = 0;



			}
			else if (Board[j][i] == Board[j-1][i]) {
				Board[j][i] = 0;
				Board[j-1][i] = 2 * Board[j-1][i];


				if (j <= 2) {
					Board[j][i] = Board[j+1][i];
					Board[j+1][i] = 0;
				}
				break;
			}
		}

		for (int j = ColNumber - 1; j>0; j--) {
			if (Board[j-1][i] == 0) {
				Board[j-1][i] = Board[j][i];
				Board[j][i] = 0;

			}
		}
	}



	for (int i = 0; i < RowNumber; i++) {
		for (int j = 0; j < ColNumber; j++) {
			if (MemoryBoard[i][j] != Board[i][j]) {
				movement++;
				return movement;
			}
		}
	}

	return movement;





}
int DownKey(void){

	int movement = 0;
	for (int i = 0; i < RowNumber; i++) {
		for (int j = 0; j < ColNumber; j++) {
			MemoryBoard[i][j] = Board[i][j];
		}
	}

	for (int i = 0; i < ColNumber; i++) {

		for (int j = 0; j <RowNumber - 1; j++) {

			if ((Board[j][i] != Board[j + 1][i]) && (Board[j + 1][i] != 0)) {
				;
			}
			else if (Board[j + 1][i] == 0) {
				Board[j + 1][i] = Board[j][i];
				Board[j][i] = 0;

			}
			else if (Board[j][i] == Board[j + 1][i]) {
				Board[j][i] = 0;
				Board[j + 1][i] = 2 * Board[j + 1][i];


				if (j >= 1) {
					Board[j][i] = Board[j - 1][i];
					Board[j - 1][i] = 0;
				}
				break;

			}

		}
		for (int j = 0; j < RowNumber - 1; j++) {
			if (Board[j + 1][i] == 0) {
				Board[j + 1][i] = Board[j][i];
				Board[j][i] = 0;

			}
		}
	}

	

	for (int i = 0; i < RowNumber; i++) {
		for (int j = 0; j < ColNumber; j++) {
			if (MemoryBoard[i][j] != Board[i][j]) {
				movement++;
				return movement;
			}
		}
	}

	return movement;




}
int RightKey(void){

	int movement = 0;
	for (int i = 0; i < RowNumber; i++){
		for (int j = 0; j < ColNumber; j++){
			MemoryBoard[i][j] = Board[i][j];
		}
	}

	for (int i = 0; i < RowNumber; i++) {

		for (int j = 0; j <ColNumber-1; j++) {

			if ((Board[i][j] != Board[i][j + 1]) && (Board[i][j + 1] != 0)) {
				;
			}
			else if (Board[i][j + 1] == 0) {
				Board[i][j + 1] = Board[i][j];
				Board[i][j] = 0;

			}
			else if (Board[i][j] == Board[i][j + 1]) {

				if ((j==1||j==0) && (Board[i][j] == Board[i][j+2]) ) {

					Board[i][j + 2] = 2 * Board[i][j];
					Board[i][j +1] = Board[i][j];
					Board[i][j] = 0;
				}
				else {
					Board[i][j] = 0;
					Board[i][j + 1] = 2 * Board[i][j + 1];
				}

				break;

			}
			
		}
		for (int j = 0; j < ColNumber - 1; j++){
			if (Board[i][j + 1] == 0) {
				Board[i][j + 1] = Board[i][j];
				Board[i][j] = 0;

			}
		}
	}

	for (int i = 0; i < RowNumber; i++){
		for (int j = 0; j < ColNumber; j++){
			if (MemoryBoard[i][j] != Board[i][j]){
				movement++;
				return movement;
			}
		}
	}

	return movement;

}
int LeftKey(void){

	int movement = 0;
	for (int i = 0; i < RowNumber; i++){
		for (int j = 0; j < ColNumber; j++){
			MemoryBoard[i][j] = Board[i][j];
		}
	}

	for (int i = 0; i < RowNumber; i++) {

		for (int j = ColNumber-1; j >0; j--) {

			if ((Board[i][j] != Board[i][j - 1]) && (Board[i][j - 1] != 0)) {
				;
			}
			else if (Board[i][j - 1] == 0) {
				Board[i][j - 1] = Board[i][j];
				Board[i][j] = 0;



			}
			else if (Board[i][j] == Board[i][j - 1]) {
				Board[i][j] = 0;
				Board[i][j - 1] = 2 * Board[i][j - 1];


				if (j <= 2) {
					Board[i][j] = Board[i][j+1];
					Board[i][j+1] = 0;
				}
				break;
			}
		}

		for (int j = ColNumber-1; j>0; j--) {
			if (Board[i][j - 1] == 0) {
				Board[i][j - 1] = Board[i][j];
				Board[i][j] = 0;

			}
		}
	}
	for (int i = 0; i < RowNumber; i++){
		for (int j = 0; j < ColNumber; j++){
			if (MemoryBoard[i][j] != Board[i][j]){
				movement++;
				return movement;
			}
		}
	}

	return movement;

}
//2048 움직이는것




int main(void){
	system("title AI2048");


	int iChar;
	srand(time(NULL));
	PrintUI();
	scanf("%d", &iChar);
	system("mode con:cols=20 lines=10");
	if (iChar == 1){


		system("cls");
		for (int i = 0; i < 2; i++){
			InitialNumber();
		}
		//test
		//Board[0][0] = Board[0][2] = Board[0][3] = 2;
		
		PrintBoard();

			while (1){
				getch();// 버퍼 비우기


				if ((_kbhit() ==0) && GetAsyncKeyState(VK_UP) < 0) {
				
					system("cls");
					if (UpKey() > 0) {
						RandomNumber();
					}
					PrintBoard();
	

				}
				if ((_kbhit() == 0) && GetAsyncKeyState(VK_DOWN) < 0) {

					system("cls");
					if (DownKey() > 0){
						RandomNumber();
					}
					PrintBoard();
				}
				if ((_kbhit() == 0) && GetAsyncKeyState(VK_RIGHT) < 0) {

					system("cls");
					if (RightKey() > 0){
						RandomNumber();
					}
					PrintBoard();
				}
				if ((_kbhit() == 0) && GetAsyncKeyState(VK_LEFT) < 0) {
					system("cls");
					if (LeftKey() > 0){
						RandomNumber();
					}
					PrintBoard();
				}
				
			}//나중에 바뀔것

		}
	
		else if (iChar == 2){
			system("cls");

		}
		else if (iChar == 3){
			system("cls");
		}
		else if (iChar == 4){
			system("cls");
			printf("종료 \n");

		}
		else{
			;
		}



	system("title AI2048");
	system("pause");
	return 0;
}