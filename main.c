#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define STR 20


void hidecursor()
{
	HANDLE hCons;
	CONSOLE_CURSOR_INFO cci;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.dwSize = 1;
	cci.bVisible = 0;
	SetConsoleCursorInfo(hCons, &cci);
}
void gotoxy(int column, int row)
{
	HANDLE hCons;
	COORD crd;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	//#ifdef MY_DEBUG
	//  if (hCons == INVALID_HANDLE_VALUE || hCons == 0) printf("\nERROR!!!\n");
	//#endif  	  
	crd.X = (short)column;
	crd.Y = (short)row;
	//#ifedf MY_DEBUG
	// if (SetConsoleCursorPosition(hCons,crd) == 0) printf("\nERROR2\n");
	//#else 
	SetConsoleCursorPosition(hCons, crd);
	//#endif
}
int main() {
	
	hidecursor();
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD size;
	DWORD delay = 75;
	int f = 0 , i=0;
	char sim = 0;
	char mass[STR][STR];
	
	gotoxy(0, 0);
	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < STR; j++) {
			mass[i][j] = ' ';
			printf("%c", mass[i][j]);
			//printf("&\n");
		}
		gotoxy(0, i);
	}
	
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | 2 );
	//printf("!\n");
	do {
		for (i = 1; i < STR; i++) {
			gotoxy(0, i - 1);
			for (int j = 0; j < STR; j++) {
				mass[i-1][j] = mass[i][j];
				gotoxy(j, i - 1);
				printf("%c", mass[i][j]);
				
			}
			
			
		}
		gotoxy(0, STR-1);
		for (int j = 0; j < STR; j++) {
			mass[STR-1][j] = rand() % (255 - 32 + 1) + 32;
		
			printf("%c", mass[STR-1][j]);
			
		}
		
		Sleep(delay);
				
		
	
		

	} while (f == 0);
	getchar();
	return 0;
}