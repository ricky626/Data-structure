#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>
//1번
/*
int main()
{
for (int i = 1; i < 5; i++)
{
for (int j = 0; j < i; j++)
{
printf("*");
Sleep(1000);
}
printf("\n");
}
return 0;
}*/

/*
int main()
{
int line = 0;

scanf_s("%d", &line);

for (int i = 1; i < line + 1; i++)
{
for (int j = 0; j < i; j++)
{
printf("*");
Sleep(1000);
}
printf("\n");
}
return 0;
}*/

/*
int main()
{
int line = 0;

scanf_s("%d", &line);

for (int i = 1; i < line + 1; i++)
{
for (int j = 0; j < i; j++)
{
printf("%d", j + 1);
Sleep(1000);
}
printf("\n");
}
return 0;
}*/

/*4-6
int main()
{
int count = 20;
int n = 0;

for (int i = 0; i < count; i++)
{
system("cls");

for (int j = 0; j < i; j++)//뒤에 공백
{
printf(" ");
}
//printf("C");
switch (n)
{
case 0:
n = 1;
printf("C");
break;
case 1:
n = 0;
printf("c");
break;
}
for (int j = count - 1; j > i; j--)//먹는부분
printf(",");
Sleep(200);
}
return 0;
}
*/
/*
int main()
{
char c = 'c';
int k = _getch();

while (1)
{
if (_kbhit()) //키 버퍼에 값이 남아있으면 1 남아있지않으면 0 리턴
{
k = _getch();
if (k == 77)
{
printf("d");
}
else if (k == 75)
{
printf("c");
}
}
}
return 0;
}
*/
/*
void draw(int count, int max)
{
for (int i = 0; i < count; i++)
{
system("cls");
for (int j = 0; j < i; j++) //뒤에 공백
{
printf(" ");
}
printf("C");

for (int j = max - (i + 1); j > 0; j--) //먹는부분
{
printf("0");
}
}
}

int main()
{
int max = 20;
int n = 0;
int count = 0;
int i, j, k;
char key;

while (1)
{
key = _getch();
if (key == 'd' && count < max)
{
count++;
draw(count, max);
printf("%d", count);
}
else if (key == 'g' && count >= 2)
{
count--;
draw(count, max);
printf("%d", count);
}
}
return 0;
}
*/

/*
for (i = 0; i < max; i++)
{
system("cls");

for (j = 0; j < i; j++)//뒤에 공백
printf(" ");

switch (n)
{
case 0:
n = 1;
printf("C");
break;
case 1:
n = 0;
printf("c");
break;
}
for (k = max - 1; k > i; k--)//먹는부분
printf(",");
Sleep(100);
}*/

/*
int main()
{
int max = 20;
int count = 1;
char c = 0;

while (1)
{
system("cls");


for (int i = 0; i < count-1; i++)
{
printf(" ");
}
printf("C");

for (int j = max-1; j >= count; j--)
{
printf(",");
}

c = _getch();

if (c == 77 && count < max) // ->
{
count++;
}
else if (c == 75 && count >= 2) // <-
{
count--;
}
}
return 0;
}
*/
/*
int main()
{
int max = 10;
for (int i = 0; i < max; i++)
{
system("cls");

for (int j = max - 1; j > i; j--)
{
printf(",");
}
printf("C");

Sleep(2000);
}
return 0;
}*/


/*
int main()
{
int max = 20;
int count = 1;
char c = 0;
int n = 0;
int i = 0;

while (1)
{
system("cls");

for (i = 0; i < count - 1; i++)
{
printf(" ");
}
if (i % 2 == 0)
{
printf("C");
}
else
printf("c");


for (int j = max - 1; j >= count; j--)
printf(",");

c = _getch();
if (c == 'd' && count < max)
count++;
else if (c == 'g' && count > 1)
count--;
}
return 0;
}
*/
/*
int main()
{
int max = 10;
int count = 1;
char c = 0;
int i = 0;

while (1)
{
system("cls");

for (i = 0; i < count - 1; i++)
{
printf(" ");
}

if (i % 2 == 0)
printf("c");
else
printf("C");

for (int j = max - 1; j >= count; j--)
printf(",");

c = _getch();

if (c == 77 && count < max)
count++;
else if (c == 75 && count > 1)
count--;
}

return 0;
}*/


/*
int main()
{
int max = 10;
int count = 1;
char c = 0;
while (1)
{


for (int i = -1; i < count-1; i++)
{
system("cls");
for (int j = max - 1; j >= count; j--)
{
printf(",");
}
}

printf("C");

c = _getch();

if (c == 'd' && count < max)
count++;
else if (c == 'g' && count >= 2)
count--;
printf("\n%d\n", count);
}

return 0;
}

*/

/*
int main()
{
int max = 20;
int count = 1;
char c = 0;
int i = 0;

while (true)
{
system("cls");
for (i = 0; i < count - 1; i++)
printf(" ");

if (i % 2 == 0)
printf("C");
else
printf("c");

for (int j = max - 1; j >= count; j--)
printf(",");


c = _getch();
if (c == 77 && count < max)
count++;
else if (c == 75 && count > 1)
count--;
}
return 0;
}
*/

/*
void gotoxy(int x, int y){
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int check = 1;

void Draw_Stone()
{
	if (check == 1)
	{
		printf("○");
		check = 2;
	}
	else if (check == 2)
	{
		printf("●");
		check = 1;
	}
}

void Draw_Put_Stone(int stone[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (stone[j][i] == 1)
			{
				gotoxy(i * 2, j);
				printf("●");
			}
			else if (stone[j][i] == 2)
			{
				gotoxy(i * 2, j);
				printf("○");
			}
		}
	}
}

void Put_Stone(int Board[][20], int x, int y){
	if (Board[y][x / 2] == 0)
	{
		if (check == 1)
		{
			Board[y][x / 2] = 1;
			check = 2;
		}
		else
		{
			Board[y][x / 2] = 2;
			check = 1;
		}
	}
}

void Draw_Map()
{
	printf("┌");
	for (int i = 0; i < 17; i++)
	{
		printf("┬");
	}
	printf("┐\n");

	for (int i = 0; i < 17; i++)
	{
		printf("├");
		for (int j = 0; j < 17; j++)
		{
			printf("┼");
		}
		printf("┤\n");
	}

	printf("└");
	for (int i = 0; i < 17; i++)
	{
		printf("┴");
	}
	printf("┘");
}

int main()
{
	int x = 0, y = 0;
	int stone[20][20] = { 0, };

	Draw_Map();
	gotoxy(x, y);


	while (1)
	{
		gotoxy(20, 20);
		printf("좌표 입력 : \n");
		scanf_s("%d %d", &x, &y);


		Draw_Put_Stone(stone);
		Put_Stone(stone, x, y);

		gotoxy(0, 0);
		Draw_Stone();
		Put_Stone(stone, x, y);


	}

	printf("\n");
	return 0;
}
*/

int main()
{
	int x = 0, y = 0;
	int max = 20;
	char* board[21][21] = { 0, };
	int check = 1;

	char* black = "○";
	char* white = "●";
	int b_count = 0;
	int w_count = 0;

	board[1][1] = "┌";
	for (int i = 2; i < max; i++)
		board[1][i] = "┬";
	board[1][max] = "┐";

	for (int i = 2; i < max; i++)
	{
		board[i][1] = "├";
		for (int j = 2; j < max; j++)
		{
			board[j][i] = "┼";
		}
		board[i][20] = "┤";
	}

	board[20][1] = "└";
	for (int i = 2; i < max; i++)
		board[20][i] = "┴";
	board[20][20] = "┘";

	while (1)
	{
		system("cls");
		for (int i = 1; i <= max; i++)
		{
			for (int j = 1; j <= max; j++)
			{
				printf("%s", board[i][j]);
			}
			printf("\n");
		}
		printf("\n검은돌: %d개\n하얀돌: %d개\n", b_count, w_count);

		printf("좌표 입력 : ");
		scanf_s("%d %d", &x, &y);

		if (check == 1 && board[y][x] != white)
		{
			board[y][x] = black;
			check = 2;
			b_count++;
		}
		else if (check == 2 && board[y][x] != black)
		{
			board[y][x] = white;
			check = 1;
			w_count++;
		}
	}
	
	return 0;
}
