#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void draw_bullet(int, int);
void erase_bullet(int, int);

int main() {
	int x = 38, y = 20, px[5], py[5], bullet[5], drt = 0;
	char ch = ' ';
	setcursor(0);
	draw_ship(x, y);
	for (int i = 0; i < 5; i++) {
		bullet[i] = 0;
	}
	do {
		if (drt == 1 && x > 0) {
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (drt == 2 && x < 80) {
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a')
			{
				drt = 1;
			}
			if (ch == 'd')
			{
				drt = 2;
			}
			if (ch == 's')
			{
				drt = 0;
			}
			if (ch == ' ') {
				for (int i = 0; i < 5; i++) {
					if (bullet[i] == 0) {
						bullet[i] = 1;
						px[i] = x;
						py[i] = y - 2;
						draw_bullet(px[i], py[i]);
						break;
					}
				}
			}
			fflush(stdin);
		}
		for (int i = 0; i < 5; i++) {
			if (bullet[i] == 1)
			{
				erase_bullet(px[i], py[i]);
				py[i] = py[i] - 1;
				if (py[i] > 0) {
					draw_bullet(px[i], py[i]);
				}
				else {
					bullet[i] = 0;
				}
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");

}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(7, 0);
	printf("   A ");
}
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("     ");

}