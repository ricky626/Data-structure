#include <stdio.h>
#include <Windows.h>

#define MAX 20
/*
int main()
{
char* board[MAX][MAX] = { 0, };
char* black = "○";
char* white = "●";
int check = 1;
int b_count = 0, w_count = 0;
int x = 0, y = 0;
int cx = 0, cy = 0;
int bb_count[2][MAX] = { 0, };
int ww_count[2][MAX] = { 0, };


//┌┬┐ ├┼┤ └┴┘

board[0][0] = "┌";
board[0][MAX - 1] = "┐";
board[MAX - 1][0] = "└";
board[MAX - 1][MAX - 1] = "┘";

for (int i = 1; i <= MAX - 2; i++)
{
board[i][0] = "├";
board[i][MAX - 1] = "┤";
board[0][i] = "┬";
board[MAX - 1][i] = "┴";

for (int j = 1; j <= MAX - 2; j++)
{
board[j][i] = "┼";
}
}

while (1)
{

system("cls");

for (cy = 0; cy < MAX; cy++)
{
for (cx = 0; cx < MAX; cx++)
{
printf("%s", board[cy][cx]);
}

printf(" %d %d", bb_count[0][cy], ww_count[0][cy]);
printf("\n");
}

printf(" ");

for (cx = 0; cx < MAX; cx++)
{
printf("%d ", bb_count[1][cx]);
}


printf("\n");
printf(" ");

for (cx = 0; cx < MAX; cx++)
{
printf("%d ", ww_count[1][cx]);
}



printf("\n검은돌 : %d개  하얀돌 : %d개\n", b_count, w_count);
printf("좌표 입력 : ");
scanf_s("%d %d", &x, &y);

if (x < MAX && y < MAX && x > -1 && y > -1)
{
if (check == 1 && board[x][y] != white)
{
board[y][x] = black;
check = 2;
b_count++;
bb_count[0][x]++;
bb_count[1][x]++;
}
else if (check == 2 && board[x][y] != black)
{
board[y][x] = white;
check = 1;
w_count++;
ww_count[0][x]++;
ww_count[1][x]++;
}
}
}
return 0;
}*/

#include <stdio.h>
#include <Windows.h>

#define MAX 20

int main()
{
	char* board[MAX][MAX] = { 0, };
	char* black = "○";
	char* white = "●";
	char* bdoll = "☆";
	char* wdoll = "★";

	int	check = 1;
	int	b_count = 0, w_count = 0;
	int x = 0, y = 0;
	int cx = 0, cy = 0;
	int count = 1;

	int bb_count[2][MAX] = { 0, };
	int ww_count[2][MAX] = { 0, };

	int d_check[MAX][MAX] = { 0, };
	int d_Maxcount[2][MAX] = { 0, };
	int countcheck = 0;

	char* result[2][MAX] = { 0, };


	//┌┬┐ ├┼┤ └┴┘

	board[0][0] = "┌";
	board[0][MAX - 1] = "┐";
	board[MAX - 1][0] = "└";
	board[MAX - 1][MAX - 1] = "┘";

	for (int i = 1; i <= MAX - 2; i++)
	{
		board[i][0] = "├";
		board[i][MAX - 1] = "┤";
		board[0][i] = "┬";
		board[MAX - 1][i] = "┴";

		for (int j = 1; j <= MAX - 2; j++)
		{
			board[j][i] = "┼";
		}
	}


	while (1)
	{
		system("cls");

		for (cy = 0; cy < MAX; cy++)
		{
			for (cx = 0; cx < MAX; cx++)
			{
				printf("%s", board[cy][cx]);
			}

			printf(" %d %d", bb_count[0][cy], ww_count[0][cy]);
			if (result[0][cy] != NULL)
				printf("  %s %d", result[0][cy], d_Maxcount[0][cy]);


			printf("\n");
		}

		printf(" ");

		for (cx = 0; cx < MAX; cx++)
		{
			printf("%d ", bb_count[1][cx]);
		}


		printf("\n");
		printf(" ");

		for (cx = 0; cx < MAX; cx++)
		{
			printf("%d ", ww_count[1][cx]);
		}

		printf("\n");

		for (int i = 0; i < MAX; i++)
		{
			if (result[1][i] == NULL)
				result[1][i] = "  ";
			else
				printf("%s", result[1][i]);
		}
		printf("\n");
		
		for (int i = 0; i < MAX; i++)
		{
			printf(" %d", d_Maxcount[1][i]);
		}



		printf("\n");
		//printf("\n검은돌 : %d개  하얀돌 : %d개\n", b_count, w_count);
		printf("좌표 입력 : ");
		scanf("%d %d", &x, &y);

		if (x < MAX && y < MAX && x > -1 && y > -1)
		{
			if (check == 1 && board[y][x] != white && board[y][x] != black) //검은돌
			{
				board[y][x] = black;
				check = 2;
				b_count++;
				bb_count[0][y]++;
				bb_count[1][x]++;
				d_check[y][x] = 1;

				if (d_check[y][x] == d_check[y][x - 1] || d_check[y][x] == d_check[y][x + 1])
				{
					if (countcheck != 1)
					{
						countcheck = 1;
						d_Maxcount[0][y] = 0;
					}

					if (d_Maxcount[0][y] == 0)
						d_Maxcount[0][y] = 1;

					d_Maxcount[0][y]++;

					result[0][y] = black;


					if (board[y][x] == board[y][x - 1] || board[y][x - 1] == bdoll)
					{
						board[y][x] = bdoll;
						board[y][x - 1] = bdoll;
					}
					else if (board[y][x] == board[y][x + 1] || board[y][x + 1] == bdoll)
					{
						board[y][x] = bdoll;
						board[y][x + 1] = bdoll;
					}
				}

				if (d_check[y][x] == d_check[y - 1][x] || d_check[y][x] == d_check[y + 1][x])
				{
					if (countcheck != 1)
					{
						countcheck = 1;
						d_Maxcount[1][x] = 0;
					}

					if (d_Maxcount[1][x] == 0)
						d_Maxcount[1][x] = 1;

					d_Maxcount[1][x]++;

					result[1][x] = black;


					if (board[y][x] == board[y - 1][x] || board[y - 1][x] == bdoll)
					{
						board[y][x] = bdoll;
						board[y - 1][x] = bdoll;
					}
					else if (board[y][x] == board[y + 1][x] || board[y + 1][x] == bdoll)
					{
						board[y][x] = bdoll;
						board[y + 1][x] = bdoll;
					}
				}

			}
			else if (check == 2 && board[y][x] != black && board[y][x] != white) //흰돌
			{
				board[y][x] = white;
				check = 1;
				w_count++;
				ww_count[0][y]++;
				ww_count[1][x]++;
				d_check[y][x] = 2;

				if (d_check[y][x] == d_check[y][x - 1] || d_check[y][x] == d_check[y][x + 1])
				{
					if (countcheck != 2)
					{
						countcheck = 2;
						d_Maxcount[0][y] = 0;
					}

					if (d_Maxcount[0][y] == 0)
						d_Maxcount[0][y] = 1;


					d_Maxcount[0][y]++;


					result[0][y] = white;

					if (board[y][x] == board[y][x - 1] || board[y][x - 1] == wdoll)
					{
						board[y][x] = wdoll;
						board[y][x - 1] = wdoll;
					}
					else if (board[y][x] == board[y][x + 1] || board[y][x + 1] == wdoll)
					{
						board[y][x] = wdoll;
						board[y][x + 1] = wdoll;
					}
				}

				if (d_check[y][x] == d_check[y - 1][x] || d_check[y][x] == d_check[y + 1][x])
				{
					if (countcheck != 2)
					{
						countcheck = 2;
						d_Maxcount[1][x] = 0;
					}

					if (d_Maxcount[1][x] == 0)
						d_Maxcount[1][x] = 1;

				
					d_Maxcount[1][x]++;

					
					result[1][x] = white;

					if (board[y][x] == board[y - 1][x] || board[y - 1][x] ==  wdoll)
					{
						board[y][x] = wdoll;
						board[y - 1][x] = wdoll;
					}
					else if (board[y][x] == board[y + 1][x] || board[y + 1][x] == wdoll)
					{
						board[y][x] = wdoll;
						board[y + 1][x] = wdoll;
					}
				}
			}
		}

	}
	return 0;
}
