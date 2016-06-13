
/*
void fact(char* arr)
{
if (*arr != NULL){
fact(arr + 1);
printf("%c", *arr);
}
}

int main()
{
char arr[10] = "ABCDE";

fact(arr);

return 0;
}
*/
/*
int func(int num)
{
if (num == 0)
return 1;
return 2 * func(num - 1);
}

int main()
{
int num = 0;
int result = 0;
printf("입력 : ");
scanf("%d", &num);

result = func(num);
printf("%d\n", result);
return 0;
}*/
/*
#include <stdio.h>

int func(int num)
{
if (num == 1)
return 1;

return num * func(num - 1);
}

int main()
{
int num = 0;
int result = 0;

printf("입력 : ");
scanf("%d", &num);

result = func(num);

printf("%d", result);
return 0;
}*/

/*
void func(int n)
{
if (n == 0)
return;
func(n - 1);
while (n --> 0 )
printf("%d", n);
printf("\n");
}

int main()
{
func(5);

return 0;
}*/
/*
typedef struct unit
{
char data;
struct unit* next;
}Unit;

int main()
{
Unit *unit = NULL, *head = NULL;

unit = (Unit*)malloc(sizeof(Unit));
unit->data = 'a';

unit->next = (Unit*)malloc(sizeof(Unit));
unit->next->data = 'b';

unit->next->next = (Unit*)malloc(sizeof(Unit));
unit->next->next->data = 'c';

unit->next->next->next = NULL;

head = unit;
while (head != NULL)
{
printf("%c ", head->data);
head = head->next;
}
free(head);
free(unit->next);
free(head);

return 0;
}*/
/*
#include <stdio.h>
typedef struct unit
{
char data;
struct unit* next;
}Unit;

typedef struct Head{
Unit* head;
}HEAD;

bool add(HEAD* head, char data);
HEAD* Create();

int main()
{
HEAD* m_pHead = Create();
add(m_pHead, 'a');
add(m_pHead, 'b');
add(m_pHead, 'c');

for (int i = 0; m_pHead != NULL; i++)
{
printf("%c", m_pHead->head->data);
m_pHead->head = m_pHead->head->next;
}


return 0;
}

HEAD* Create()
{
HEAD* temp = new HEAD;
temp->head = NULL;

return temp;
}

bool add(HEAD* head, char data)
{
Unit* temp = head->head;

if (head->head == NULL)
{
head->head = new Unit;
head->head->next = NULL;
head->head->data = data;
return true;
}
else
{
while (temp->next != NULL)
temp = temp->next;

temp->next = new Unit;
temp->next->data = data;
temp->next->next = NULL;
return true;
}

return false;
}
*/
/*
#include <stdio.h>

int main()
{
int a = 0;
int b = 0;
char ch = a;

printf("두 정수 입력 : ");
scanf("%d %d", &a, &b);

printf("부호 입력 : ");
scanf("%c", &ch);

if (ch == '+')
printf("덧셈 : %d\n", a + b);
else if (ch == '-')
printf("뺄셈 : %d\n", a - b);
else if (ch == '*')
printf("곱셈 : %d\n", a * b);
else if (ch == '/')
printf("나눗셈 : %d\n", a / b);
else
printf("잘못 입력하셨습니다.");

return 0;
}*/

/*
typedef struct Node
{
int data;
Node* Prev;
Node* Next;
}Node;

Node* start = NULL;
Node* cur = NULL;

void Insert(int data);
void PrintAll();

void main()
{
int num = 0;

while (1)
{
printf("input : ");
scanf("%d", &num);
fflush(stdin);


if (num == 1)
{
printf("\n종료\n");
PrintAll();
return;
}
else
{
Insert(num);
}
}
}

void Insert(int data)
{
Node* NewNode = new Node;

NewNode->data = data;
NewNode->Prev = NULL;
NewNode->Next = NULL;

if (start == NULL)
{
start = NewNode;
cur = start;
return;
}

if (cur->data > NewNode->data)
{
while (cur->Next != NULL)
{
if (cur->Next->data < NewNode->data)
{
NewNode->Next = cur->Next;
NewNode->Prev = cur;
cur->Next->Prev = NewNode;
cur->Next = NewNode;
return;
}
cur = cur->Next;
}

NewNode->Prev = cur;
cur->Next = NewNode;
}

else
{
while (cur->Prev != NULL)
{
if (cur->Prev->data > NewNode->data)
{
NewNode->Next = cur;
NewNode->Prev = cur->Prev;
cur->Prev->Next = NewNode;
cur->Prev = NewNode;
return;
}
cur = cur->Prev;
}
NewNode->Next = cur;
cur->Prev = NewNode;
start = NewNode;
}
}

void PrintAll()
{
Node* cur = start;

while (cur->Next != NULL)
{
printf("%d ", cur->data);
cur = cur->Next;
}
printf("%d ", cur->data);
}*/
/*
int main()
{
int count = 0;

//2의배수 3의배수 아닌 것
for (int i = 1; i <= 100; i++)
{
if (i % 2 != 0 && i % 3 != 0)
{
printf("%d ", i);
count++;
}
}
printf("\n2의배수&3의배수 아닌 것 : %d개\n\n", count);

count = 0;
int j = 0;
//2의배수 3의배수 + 소수 찾기
for (int i = 1; i <= 100; i++)
{
for (j = 2; j < i; j++)
{
if (i % j == 0) break;
}
if (i == j && i % 2 != 0 && i % 3 != 0)
{
printf("%d ", i);
count++;
}
}
printf("\n소수 : %d개\n", count);

return 0;
}*/
/*
bool prime(int n, int num)
{
int i = 0;
int j = 0;
for (i = 1; i <= num; i++)
{
for (j = 2; j < i; j++)
{
if (i % j == 0)
return false;
}
if (i == j)
return true;
}

}

int main()
{
int num = 0;

printf("입력 : ");
scanf("%d", &num);

for (int i = 1; i <= num; i++)
{
if (prime(i, num) == true)
printf("%d ", i);
}

for (int i = 2; i <= num; i++)
{
for (int j = 2; j <= num; j++)
{

}
}
return 0;
}*/


//<내꺼>
//#include<stdio.h>
//int is_prime(int x);
//
//int main(void)
//{
//   int i;
//   for (i = 2; i <= 100; i++){
//      if (is_prime(i) == 1)
//         printf("%d\n", i);
//   }
//   return 0;
//}
//
//int is_prime(int n)
//{
//   int divisors = 0, i;
//   for (i = 1; i <= n; i++)
//   {
//      if (n%i == 0)
//         divisors++;
//   }
//   return (divisors == 2);
//}

//<교수님꺼>
//#include<stdio.h>
//int is_prime(int x);
//
//int main(void)
//{
//	int num = 0;
//
//	printf("입력 : ");
//	scanf("%d", &num);
//
//   
//   for (int i = 2; i <= num; i++)
//   {
//	   for (int j = num; j >= i; j--)
//	   {
//		   if (is_prime(i) == 1 && is_prime(j) == 1 && j + i == num)
//		   {
//			   printf("%d - %d + %d\n", num, i, j);
//		   }
//		   
//	   }
//	  
//   }
//   return 0;
//}
//
//
//int is_prime(int n)
//{
//   int i;
//   for (i = 2; i < n; i++)
//   {
//      if (n%i == 0)
//         return 0;
//   }
//   return 1;
//}
/*
char change(char c, int len)

{

for (int i = 0; i < len; i++)

{

if (c >= 'a' && c <= 'z')

c -= 'a' - 'A';

else if (c >= 'A' && c <= 'Z')

c += 'a' - 'A';

return c;

}

}


int main()

{

char arr[255] = { 0, };



printf("문자 입력 : ");

scanf_s("%[^\n]s", arr, sizeof(arr));

int len = strlen(arr);




for (int i = 0; i < len; i++)

{

printf("%c", change(arr[i], len));

}




return 0;

}

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct Stone
{
int x, y;
int kind;
};
typedef struct Node
{
Stone stone;
Node *next;
};
Node* Head = NULL;
void Push(int x, int y, int kind)
{
Node *newNode = new Node;
newNode->stone.x = x;
newNode->stone.y = y;
newNode->stone.kind = kind;
newNode->next = NULL;

if (Head == NULL){
Head = newNode;
return;
}
else
{
newNode->next = Head;
Head = newNode;
return;
}
}
Stone Pop()
{
Stone temp = Head->stone;
Node* cur = Head;
Head = Head->next;
delete cur;
return temp;
}
void main()
{
int i, j;
int arr[20][20] = { 0 };
int x1, y1;
int who_turn = 1;
int B = 0, W = 0;
char command;


while (1){
system("cls");
printf("전체 검은돌 %d개, 흰돌 %d개입니다.\n\n", B, W);
for (i = 0; i < 20; ++i){
for (j = 0; j < 20; ++j){
if (arr[i][j] == 0)
printf("＋");
if (arr[i][j] == 1)
printf("●");

if (arr[i][j] == 2)
printf("○");
}
printf("\n");
}
printf("\n");
scanf("%c", &command);
switch (command){
case '1':
if (who_turn == 1){
printf("검은돌의 좌표를 입력해주세요: ");
scanf("%d %d", &x1, &y1);
while (arr[x1][y1] == 2 || arr[x1][y1] == 1){
printf("이미 돌이 있습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
}
while (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20){
printf("좌표를 벗어났습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
while (arr[x1][y1] == 2 || arr[x1][y1] == 1){
printf("이미 돌이 있습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
}
}
Push(x1, y1, 1);
arr[x1][y1] = 1;
++B;
}
else{
printf("흰 돌의 좌표를 입력해주세요: ");
scanf("%d %d", &x1, &y1);
while (arr[x1][y1] == 1 || arr[x1][y1] == 2){
printf("이미 돌이 있습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
}
while (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20){
printf("좌표를 벗어났습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
while (arr[x1][y1] == 1 || arr[x1][y1] == 2){
printf("이미 돌이 있습니다. 다시 입력해주세요: ");
scanf("%d %d", &x1, &y1);
}
}
Push(x1, y1, 2);
arr[x1][y1] = 2;
++W;
}
who_turn = -who_turn;
break;
case 'U':
case 'u':
{
if (B == 0 && W == 0){
//printf("무를 돌이 없습니다\n");
break;
}
Stone temp = Pop();
arr[temp.x][temp.y] = 0;
if (who_turn == -1)
--B;
else
--W;
who_turn = -who_turn;
break;
}
case 's':
FILE*f;
f = fopen("10주차 오목test.txt", "w");
for (i = 0; i < 20; ++i){
for (j = 0; j < 20; ++j)
fprintf(f, "%d", arr[i][j]);
fprintf(f, "\n");
}
fclose(f);
break;
}
}
}


*/
/*
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct Champion
{
	char* name;
	double hp;
	double mp;
	int speed;
	int range;
	char* position;
};

typedef struct Node
{
	Champion champion;
	Node* next;
};

Node* Head = NULL;


Node* Search(char str[])
{
	Node* temp = Head;
	do
	{
		if (strcmp(temp->champion.name, str) == 0)
		{
			return temp;
		}
		else
			temp = temp->next;

	} while (temp != NULL);
	printf("존재하지 않는다\n\n");
	return NULL;
}

void Insert(Champion data)
{
	Node* newNode = new Node;
	Node* Cur = Head;

	if (Head == NULL)
	{
		Head = newNode;
		Head->champion = data;
		Head->next = NULL;
	}

	else{
		while (Cur->next != NULL)
			Cur = Cur->next;

		Cur->next = newNode;
		Cur->next->champion = data;
		Cur->next->next = NULL;
	}
}

void Delete(char str[])
{
	Node* DeleteNode = Search(str);
	Node* temp = Head;


}

void DeleteAll()
{

}

void PrintAll()
{
	Node* temp = Head;

	do{
		printf("\n Name : %s\n", temp->champion.name);
		printf("   Hp : lf\n", temp->champion.hp);
		printf("   Mp : lf\n", temp->champion.mp);
		printf("Speed : %d\n", temp->champion.speed);
		printf("Range : %d\n", temp->champion.range);
		printf("Posit : %s\n", temp->champion.position);

		temp = temp->next;
	} while (temp != NULL);
}

void FindMaxHp()
{

}

void SortByHp()
{

}

void main()
{
	Champion arr[20] = {
		{ "가렌", 616.28, 32.1, 345, 1, "top" }, { "갈리오", 577.8, 32.1, 335, 2, "mid" },
		{ "갱플랭크", 631.08, 32.1, 345, 3, "bot" }, { "그라가스", 583.52, 32.1, 330, 4, "top" },
		{ "그레이브즈", 551.12, 30, 330, 5, "top" }, { "나르", 540, 30, 325, 6, "mid" },
		{ "나서스", 561.2, 32.1, 350, 7, "bot" }, { "노틸러스", 576.48, 32.1, 325, 8, "top" },
		{ "녹턴", 582.8, 32.1, 345, 9, "mid" }, { "누누", 598.28, 32.1, 350, 10, "bot" },
		{ "니달리", 541.2, 30, 335, 11, "top" }, { "다리우스", 582.24, 32.1, 340, 12, "mid" },
		{ "다이애나", 589.2, 32.1, 345, 13, "bot" }, { "드레이븐", 557.76, 30, 330, 14, "top" },
		{ "라이즈", 558.48, 30, 340, 15, "mid" }, { "람머스", 564.48, 32.1, 335, 16, "bot" },
		{ "럭스", 477.72, 30, 330, 17, "top" }, { "럼블", 584.4, 32.1, 345, 18, "mid" },
		{ "레넥톤", 572.16, 32.1, 345, 19, "bot" }, { "나미", 489.32, 30, 335, 20, "top" }
	};

	Node* SearchNode;
	Champion InsertChamp;

	for (int i = 0; i < 20; i++)
	{
		Insert(arr[i]);
	}

	int num = 0;

	char Search_name[20] = { 0, };
	char Insert_name[20] = { 0, };
	char Delete_name[20] = { 0, };
	char Delete_position[20] = { 0, };
	char Insert_position[20] = { 0, };

	double Insert_hp = 0;
	double Insert_mp = 0;
	int Insert_speed = 0;
	int Insert_range = 0;


	while (1){
		printf("1.검색  2.삽입  3.삭제  4.포지션 삭제  5.전체 출력\n6.최대체력의 챔피언 출력  7.체력큰순서로 정렬\n--> ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("이름 입력 : ");
			scanf("%s", Search_name);
			SearchNode = Search(Search_name);

			printf("\n Name : %s\n", SearchNode->champion.name);
			printf("   Hp : %.2lf\n", SearchNode->champion.hp);
			printf("   Mp : %.2lf\n", SearchNode->champion.mp);
			printf("Speed : %d\n", SearchNode->champion.speed);
			printf("Range : %d\n", SearchNode->champion.range);
			printf("Posit : %s\n", SearchNode->champion.position);

			break;
		case 2:
			printf("Name : ");
			scanf("%s", Insert_name);
			printf("Hp : ");
			scanf("%lf", &Insert_hp);
			printf("Mp : ");
			scanf("%lf", &Insert_mp);
			printf("Speed : ");
			scanf("%d", &Insert_speed);
			printf("Range : ");
			scanf("%d", &Insert_range);
			printf("Positon : ");
			scanf("%s", Insert_position);

			InsertChamp.name = (char*)malloc(strlen(Insert_name));
			strcpy(InsertChamp.name, Insert_name);

			InsertChamp.hp = Insert_hp;
			InsertChamp.mp = Insert_mp;
			InsertChamp.speed = Insert_speed;
			InsertChamp.range = Insert_range;

			InsertChamp.position = (char*)malloc(strlen(Insert_position));
			strcpy(InsertChamp.position, Insert_position);

			Insert(InsertChamp);
			break;
		case 3:
			printf("삭제할 이름: ");
			scanf("%s", Delete_name);
			Delete(Delete_name);
			break;
		case 4:
			//DeletAll();
			break;
		case 5:
			PrintAll();
			break;
		case 6:
			//FindMaxHp();
			break;
		case 7:
			//SortByHp();
			break;

		default:
			printf("다시 입력해주세요: ");

		}
	}
}*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void plus(int(*plate)[4], char *input) // 이동 시 서로 붙어 있는 수가 있으면 서로 더해주기 위한 함수
{
	int i, j;

	if ((*input == 'w') || (*input == 'W')) // 위로 몰아넣으므로, 맨 위에 붙어있는 수들부터 차례대로 더한다.
		for (i = 0; i<3; i++)
		{
			{
				for (j = 0; j<4; j++)
				{
					if (plate[i][j] == plate[i + 1][j])
					{
						plate[i][j] *= 2;
						plate[i + 1][j] = 0;
					}
				}
			}
		}

	else if ((*input == 's') || (*input == 'S')) // 아래로 몰아넣으므로, 맨 아래에 붙어있는 수들끼리 차례대로 더한다.
		for (i = 3; i>0; i--)
		{
			{
				for (j = 3; j >= 0; j--)
				{
					if (plate[i][j] == plate[i - 1][j])
					{
						plate[i][j] *= 2;
						plate[i - 1][j] = 0;
					}
				}
			}
		}

	else if ((*input == 'a') || (*input == 'A')) // 원리는 같다.
		for (j = 0; j<3; j++)
		{
			{
				for (i = 0; i<4; i++)
				{
					if (plate[i][j] == plate[i][j + 1])
					{
						plate[i][j] *= 2;
						plate[i][j + 1] = 0;
					}
				}
			}
		}

	else if ((*input == 'd') || (*input == 'D')) // 원리는 같다.
		for (j = 3; j>0; j--)
		{
			{
				for (i = 3; i >= 0; i--)
				{
					if (plate[i][j] == plate[i][j - 1])
					{
						plate[i][j] *= 2;
						plate[i][j - 1] = 0;
					}
				}
			}
		}
}

void move(int(*plate)[4], char *input) // 이동 방향으로 수들을 모조리 몰아넣기 위한 함수
{
	int i, j, k;

	if ((*input == 'w') || (*input == 'W'))
		for (k = 0; k<10; k++) // 충분히 여러번 반복해서 완전히 몰아넣게 하기 위함
			for (i = 0; i<3; i++)
			{
				{
					for (j = 0; j<4; j++)
					{
						if (plate[i][j] == 0)
						{
							plate[i][j] = plate[i + 1][j];
							plate[i + 1][j] = 0;
						}
					}
				}
			}

	else if ((*input == 's') || (*input == 'S'))
		for (k = 0; k<10; k++)
			for (i = 3; i>0; i--)
			{
				{
					for (j = 3; j >= 0; j--)
					{
						if (plate[i][j] == 0)
						{
							plate[i][j] = plate[i - 1][j];
							plate[i - 1][j] = 0;
						}
					}
				}
			}

	else if ((*input == 'a') || (*input == 'A'))
		for (k = 0; k<10; k++)
			for (j = 0; j<3; j++)
			{
				{
					for (i = 0; i<4; i++)
					{
						if (plate[i][j] == 0)
						{
							plate[i][j] = plate[i][j + 1];
							plate[i][j + 1] = 0;
						}
					}
				}
			}

	else if ((*input == 'd') || (*input == 'D'))
		for (k = 0; k<10; k++)
			for (j = 3; j>0; j--)
			{
				{
					for (i = 3; i >= 0; i--)
					{
						if (plate[i][j] == 0)
						{
							plate[i][j] = plate[i][j - 1];
							plate[i][j - 1] = 0;
						}
					}
				}
			}
}

void main()
{
	int plate[4][4] = { 0 };
	int before[4][4] = { 0 };

	int i, j, width, vertical, count = 0, first = 0, finish = 0;

	char input;

	srand((unsigned)time(NULL));

	width = rand() % 4;
	vertical = rand() % 4;


	printf("Welcome to the 2048 game.\n\n");
	printf("coded by 김성보\n\n");
	printf("w : up,   s : down,   a : left,   d : right,   b : back\n\n");
	printf("Please press any key to start\n\n\n");

	scanf("%c", &input);
	fflush(stdin);
	system("cls");

restart:


	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			plate[i][j] = 0;
	plate[width][vertical] = 2; // 맨 처음 시작할 때 아무 칸에서나 랜덤하게 2가 생겨나게 하기 위함

	while (1)
	{
		for (i = 0; i<4; i++)
		{
			for (j = 0; j<4; j++)
			{
				if (plate[i][j] != 0)
				{
					printf("[%5d]", plate[i][j]);
				}

				else
					printf("[     ]");
			}
			printf("\n\n\n\n\n");
		}

		input = getchar();
		fflush(stdin);
		system("cls");

		for (i = 0; i<3; i++)
		{
			for (j = 0; j <= 3; j++)
			{
				if (plate[i][j] == plate[i + 1][j]) // 세로로 같은 숫자가 서로 붙어있는 경우가 하나라도 있으면 finish=1
					finish = 1;
			}
		}

		for (j = 0; j<3; j++)
		{
			for (i = 0; i <= 3; i++)
			{
				if (plate[i][j] == plate[i][j + 1]) // 가로로 같은 숫자가 서로 붙어있는 경우가 하나라도 있으면 finish=1
					finish = 1;
			}
		}

		for (i = 0; i<4; i++)
		{
			for (j = 0; j<4; j++)
			{
				if (plate[i][j] == 0) // 한 칸이라도 비어있으면 finish=1
					finish = 1;
			}
		}

		if (finish == 0) // 같은 숫자가 서로 붙어있는 경우가 아얘 없거나, 비어있는 칸도 없어서 더 이상의 게임 진행이 불가능한 경우
			break;

		finish = 0;

		if (input == 'w' || input == 'W' || input == 'a' || input == 'A' || input == 's' || input == 'S' || input == 'd' || input == 'D')
		{
			count = 0;
			first = 1;

			for (i = 0; i<4; i++)
			{
				for (j = 0; j<4; j++)
				{
					before[i][j] = plate[i][j];
				}
			}

			move(plate, &input);
			plus(plate, &input);
			move(plate, &input);


			for (i = 0; i<4; i++)
			{
				for (j = 0; j<4; j++)
				{
					if (before[i][j] != plate[i][j]) // 바로 전의 칸과 현재의 칸이 완벽히 같은지를 구별하기 위함
						count = 1;
				}
			}

			if (count == 0)
				goto end;


			width = rand() % 4;
			vertical = rand() % 4;

			for (i = 0; i<4; i++)
			{
				for (j = 0; j<4; j++)
				{
					if (plate[i][j] == 0)
						count = 1;
				}
			}

			if (count == 1)
				while (1)
				{
					if (plate[width][vertical] == 0)
					{
						plate[width][vertical] = 2;
						break;
					}

					width = rand() % 4;
					vertical = rand() % 4;
				}
		end:
			count = 0;
		}
		else if (input == 'b' || input == 'B')
		{
			if (first == 0)
				printf("맨 처음에는 뒤로 갈 수 없습니다!\n\n");

			else if (count != 1)
				for (i = 0; i<4; i++)
				{
					for (j = 0; j<4; j++)
					{
						plate[i][j] = before[i][j];
						before[i][j] = 0;
					}
				}
			else
				printf("뒤로가기는 바로 전의 상태로밖에 돌아갈 수 없습니다.\n\n");

			count = 1;
		}
	}

	system("cls");
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("[%5d]", plate[i][j]);
		}

		printf("\n\n\n\n\n");
	}

	printf("\n\nGAME OVER\n\n");
	printf("r : restart,   e : exit game");
	scanf("%c", &input);

	while (1)
	{
		if (input == 'r' || input == 'R')
		{
			system("cls");
			goto restart;
		}
		else if (input == 'e' || input == 'E')
		{
			system("cls");
			break;
		}
	}
}
