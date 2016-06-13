#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char* name;
	double hp;
	double mp;
	int speed;
	int range;
	char* position;
}Unit;

#define SIZE 21

bool check(Unit unit[], char str[], int i, int sel)
{
	if (i == SIZE)
		return false;
	if (unit[i].name == NULL)
		check(unit, str, i + 1, sel);

	else if (unit[i].name != NULL)
	{
		if (sel == 0)
		{
			if (strcmp(unit[i].name, str) == 0)
			{
				return true;
			}
			else
				check(unit, str, i + 1, sel);
		}
		else if (sel == 1)
		{
			if (strcmp(unit[i].position, str) == 0)
			{
				return true;
			}
			else
				check(unit, str, i + 1, sel);
		}
	}
}

void PrintAll(Unit unit[], int i)
{
	printf("\n Name : %s\n", unit[i].name);
	printf("   Hp : %.2lf\n", unit[i].hp);
	printf("   Mp : %.2lf\n", unit[i].mp);
	printf("Speed : %d\n", unit[i].speed);
	printf("Range : %d\n", unit[i].range);
	printf("Posit : %s\n", unit[i].position);
	if (i == SIZE - 1)
		return;
	PrintAll(unit, i + 1);
}

void Search(Unit unit[], char name[], int i)
{
	if (unit[i].name == NULL)
		return;

	if (strcmp(unit[i].name, name) == 0)
	{
		printf("\n Name : %s\n", unit[i].name);
		printf("   Hp : %.2lf\n", unit[i].hp);
		printf("   Mp : %.2lf\n", unit[i].mp);
		printf("Speed : %d\n", unit[i].speed);
		printf("Range : %d\n", unit[i].range);
		printf("Posit : %s\n", unit[i].position);
	}
	else
		Search(unit, name, i + 1);
}

void Insert(Unit unit[], char name[], double hp, double mp, int speed, int range, char position[], int i)
{
	if (check(unit, name, 0, 0) == true)
	{
		printf("\n Same Name!!\n\n");
		return;
	}
	if (unit[i].name == NULL)
	{
		unit[i].name = (char*)malloc(strlen(name));
		strcpy(unit[i].name, name);

		unit[i].hp = hp;
		unit[i].mp = mp;
		unit[i].speed = speed;
		unit[i].range = range;

		unit[i].position = (char*)malloc(strlen(position));
		strcpy(unit[i].position, position);
		printf("\nInsert Complete!!\n\n");

	}
	Insert(unit, name, hp, mp, speed, range, position, i + 1);
}

void Delete(Unit unit[], char name[], int i)
{
	if (check(unit, name, 0, 0) == false)
		return;

	if (unit[i].name == NULL)
		Delete(unit, name, i + 1);
	else if (unit[i].name != NULL)
	{
		if (strcmp(unit[i].name, name) == 0)
		{
			unit[i].name = NULL;
			unit[i].hp = 0;
			unit[i].mp = 0;
			unit[i].speed = 0;
			unit[i].range = 0;
			unit[i].position = NULL;
			printf("\nDelete Complete!!\n\n");
		}
		else
			Delete(unit, name, i + 1);
	}
}

void DeleteAll(Unit unit[], char position[], int i)
{
	if (check(unit, position, 0, 1) == false)
		return;

	if (unit[i].name == NULL)
		DeleteAll(unit, position, i + 1);

	else
	{
		if (strcmp(unit[i].position, position) == 0)
		{
			unit[i].name = NULL;
			unit[i].hp = 0;
			unit[i].mp = 0;
			unit[i].speed = 0;
			unit[i].range = 0;
			unit[i].position = NULL;
			DeleteAll(unit, position, i + 1);
		}
		else
			DeleteAll(unit, position, i + 1);
	}
}

int FindMaxHp(Unit unit[], double Max_hp, int i, int index)
{
	if (i == SIZE - 1)
		return index;
	if (unit[i].hp > Max_hp)
	{
		Max_hp = unit[i].hp;
		index = i;
	}
	FindMaxHp(unit, Max_hp, i + 1, index);
}

void SortByHp(Unit unit[], Unit unit2[], Unit Utemp, int i, int j)
{
	if (i == SIZE - 1)
		return;
	else if (j != SIZE - 1)
	{
		if (unit[i].hp > unit[j].hp)
		{
			Utemp = unit[i];
			unit[i] = unit[j];
			unit[j] = Utemp;

		}
		SortByHp(unit, unit2, Utemp, i, j + 1);
	}
	else
		SortByHp(unit, unit2, Utemp, i + 1, 0);
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
	char Delete_name[20] = { 0, };
	char Delete_pos[20] = { 0, };

	char Insert_name[20] = { 0, };
	char Insert_position[20] = { 0, };
	double Insert_hp = 0;
	double Insert_mp = 0;
	int Insert_speed = 0;
	int Insert_range = 0;

	int index = 0;

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
			printf("Name input : ");
			scanf("%s", Insert_name);
			printf("Hp input : ");
			scanf("%lf", &Insert_hp);
			printf("Mp input : ");
			scanf("%lf", &Insert_mp);
			printf("Speed input : ");
			scanf("%d", &Insert_speed);
			printf("Range input : ");
			scanf("%d", &Insert_range);
			printf("Position input : ");
			scanf("%s", Insert_position);

			Insert(unit, Insert_name, Insert_hp, Insert_mp, Insert_speed, Insert_range, Insert_position, 0);
			break;
		case 3://Delete
			printf("Delete input : ");
			scanf("%s", Delete_name);

			Delete(unit, Delete_name, 0);
			break;
		case 4://DeleteAll
			printf("Position input : ");
			scanf("%s", Delete_pos);

			DeleteAll(unit, Delete_pos, 0);
			break;
		case 5://PrintAll
			PrintAll(unit, 0);
			break;
		case 6://FindMaxHp
			index = FindMaxHp(unit, 0, 0, 0);

			printf("\n Name : %s\n", unit[index].name);
			printf("    Hp : %.2lf\n", unit[index].hp);
			printf("    Mp : %.2lf\n", unit[index].mp);
			printf("Speed : %d\n", unit[index].speed);
			printf("Range : %d\n", unit[index].range);
			printf("  Pos : %s\n", unit[index].position);
			break;
		case 7://SortByhp
			SortByHp(unit, unit, Utemp, 0, 0);
			printf("\nSortByHp Complete!!\n\n");
			break;
		}
	}
	return 0;
}