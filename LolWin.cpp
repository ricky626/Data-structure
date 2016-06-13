#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 21

typedef struct {
	char* name;//4
	double hp;//8
	double mp;//8
	int speed;//4
	int range;//4
	char* position;//4
} Unit;

void PrintAll(Unit unit[], int index)
{
	if (index == SIZE)
		return;
	
	printf("\nName : %s\n", unit[index].name);
	printf("   Hp : %.2lf\n", unit[index].hp);
	printf("   Mp : %.2lf\n", unit[index].mp);
	printf(" Speed : %d\n", unit[index].speed);
	printf(" Range : %d\n", unit[index].range);
	printf(" Posit : %s\n", unit[index].position);

	PrintAll(unit, index + 1);	
}

void Search(Unit unit[], char Search_name[], int index)
{
	if (unit[index].name == NULL)
		return;
	if (strcmp(unit[index].name, Search_name) == 0)
	{
		printf("\nName : %s\n", unit[index].name);
		printf("   Hp : %.2lf\n", unit[index].hp);
		printf("   Mp : %.2lf\n", unit[index].mp);
		printf(" Speed : %d\n", unit[index].speed);
		printf(" Range : %d\n", unit[index].range);
		printf(" Posit : %s\n", unit[index].position);
	}
	else
		Search(unit, Search_name, index + 1);
}

void Insert(Unit unit[], char name[], double hp, double mp, int speed, 
	int range, char position[], int index)
{
	if (unit[index].name == NULL)
	{
		unit[index].name = (char*)malloc(strlen(name));
		strcpy(unit[index].name, name);

		unit[index].hp = hp;
		unit[index].mp = mp;
		unit[index].speed = speed;
		unit[index].range = range;

		unit[index].position = (char*)malloc(strlen(position));
		strcpy(unit[index].position, position);
	}
	else
		Insert(unit, name, hp, mp, speed, range, position, index + 1);
}


void Delete(Unit unit[], char Delete_name[], int index)
{
	if (strcmp(unit[index].name, Delete_name) == 0)
	{
		unit[index].name = NULL;
		unit[index].hp = 0;
		unit[index].mp = 0;
		unit[index].speed = 0;
		unit[index].range = 0;
		unit[index].position = NULL;
	}
	else
		Delete(unit, Delete_name, index + 1);
		
}

void DeleteAll(Unit unit[], char Delete_position[], int index)
{
	if (unit[index].name == NULL)
		return;
	if (strcmp(unit[index].position, Delete_position) == 0)
	{
		unit[index].name = NULL;
		unit[index].hp = 0;
		unit[index].mp = 0;
		unit[index].range = 0;
		unit[index].speed = 0;
		unit[index].position = NULL;
	}
	DeleteAll(unit, Delete_position, index + 1);
}

int FindMaxHp(Unit unit[], double Max_hp, int i, int index)
{
	if (index == SIZE)
		return i;

	if (unit[index].hp > Max_hp)
	{
		Max_hp = unit[index].hp;
		i = index;
	}
	FindMaxHp(unit, Max_hp, i, index + 1);
}

void SortByHp(Unit unit[], Unit temp, int index)
{
	if (index == SIZE)
		return;
	
	for (int j = 0; j < SIZE; j++)
	{
		if (unit[index].hp > unit[j].hp)
		{
			temp = unit[index];
			unit[index] = unit[j];
			unit[j] = temp;
		}
	}

	SortByHp(unit, temp, index + 1);
}

int main()
{
	Unit unit[SIZE] = {
		{ "Lux", 477.72, 334, 330, 550, "mid" },
		{ "Ashe", 527.72, 231.8, 325, 600, "bot" },
		{ "Sona", 482.36, 340.6, 325, 550, "bot" },
		{ "Nocturn", 582.8, 273.8, 345, 125, "jungle" },
		{ "Amumu", 613.12, 287.2, 335, 125, "jungle" },
		{ "Veigar", 492.76, 342.4, 340, 525, "mid" },
		{ "Taric", 619.2, 349.08, 340, 125, "bot" },
		{ "Leesin", 570.8, 200, 350, 125, "jungle" },
		{ "Irelia", 607.2, 288.8, 345, 125, "top" },
		{ "Corki", 512.76, 305.16, 325, 550, "bot" },
		{ "Alistar", 513.36, 278.84, 330, 125, "bot" },
		{ "Tryndamere", 625.64, 100, 345, 125, "top" },
		{ "Fiddlesticks", 524.4, 350.12, 335, 480, "jungle" },
		{ "Vayne", 498.44, 231.8, 330, 550, "bot" },
		{ "Anivia", 467.6, 346.04, 325, 600, "mid" },
		{ "Morgana", 547.48, 340.8, 335, 450, "mid" },
		{ "Graves", 551.12, 322.2, 330, 525, "bot" },
		{ "Gangplank", 631.08, 282.2, 345, 125, "top" },
		{ "Ezreal", 484.4, 310.6, 325, 550, "bot" },
		{ "Singed", 542.76, 290.6, 345, 125, "top" }
	};
	Unit Utemp = { 0, };

	int sel = 0;
	char Search_name[20] = { 0, };
	char Insert_name[20] = { 0, };
	double Insert_hp = 0;
	double Insert_mp = 0;
	int Insert_range = 0;
	int Insert_speed = 0;
	char Insert_position[20] = { 0, };
	char Delete_name[20] = { 0, };
	char Delete_position[20] = { 0, };
	int check = 0;

	while (1)
	{
		printf("\n(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n Input : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1://Search
			printf("Search input : ");
			scanf("%s", Search_name);

			Search(unit, Search_name, 0);
			break;
		case 2://Insert
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
			printf("Position : ");
			scanf("%s", Insert_position);
			
		
			Insert(unit, Insert_name, Insert_hp, Insert_mp, Insert_speed, Insert_range, Insert_position, 0);
			break;
		case 3://Delete
			printf("Delete input : ");
			scanf("%s", Delete_name);

			Delete(unit, Delete_name, 0);
			break;
		case 4://Delete All
			printf("DeletePosition input : ");
			scanf("%s", Delete_position);

			DeleteAll(unit, Delete_position, 0);
			break;
		case 5://PrintAll
			PrintAll(unit, 0);
			break;
		case 6://FindMaxHp

			printf("\nName : %s\n", unit[FindMaxHp(unit, 0, 0, 0)].name);
			printf("   Hp : %.2lf\n", unit[FindMaxHp(unit, 0, 0, 0)].hp);
			printf("   Mp : %.2lf\n", unit[FindMaxHp(unit, 0, 0, 0)].mp);
			printf(" Speed : %d\n", unit[FindMaxHp(unit, 0, 0, 0)].speed);
			printf(" Range : %d\n", unit[FindMaxHp(unit, 0, 0, 0)].range);
			printf(" Posit : %s\n", unit[FindMaxHp(unit, 0, 0, 0)].position);
			break;

		case 7://SortByHp
			SortByHp(unit, Utemp, 0);
			printf("\nSortByHp Complete!!\n\n");
			break;
		}
	}
	return 0;
}