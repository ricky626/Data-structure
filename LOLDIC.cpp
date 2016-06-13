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
	int count = 0;
	char Search_name[20] = { 0, };
	char Insert_name[20] = { 0, };
	double Insert_hp = 0;
	double Insert_mp = 0;
	int Insert_range = 0;
	int Insert_speed = 0;
	char Insert_position[20] = { 0, };
	char Delete_name[20] = { 0, };
	char Delete_position[20] = { 0, };
	double Max_hp = 0;
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

			for (int i = 0; i < SIZE; i++)
			{
				if (unit[i].name == NULL)
				{
					printf("\nFind Fail\n\n");
					break;
				}
				if (strcmp(unit[i].name, Search_name) == 0)
				{
					printf("\n Name : %s\n", unit[i].name);
					printf("   Hp : %.2lf\n", unit[i].hp);
					printf("   Mp : %.2lf\n", unit[i].mp);
					printf("Speed : %d\n", unit[i].speed);
					printf("Range : %d\n", unit[i].range);
					printf("Posit : %s\n\n", unit[i].position);
					break;
				}
			}
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

			
			for (int i = 0; i < SIZE; i++)
			{
				if (unit[i].name == NULL)
				{
					unit[i].name = (char*)malloc(strlen(Insert_name));
					strcpy(unit[i].name, Insert_name);

					unit[i].hp = Insert_hp;
					unit[i].mp = Insert_mp;
					unit[i].speed = Insert_speed;
					unit[i].range = Insert_range;

					unit[i].position = (char*)malloc(strlen(Insert_position));
					strcpy(unit[i].position, Insert_position);

					printf("\nInsert Data Load!\n\n");
					break;
				}
			}
			break;
		case 3://Delete
			printf("Delete input : ");
			scanf("%s", Delete_name);

			for (int i = 0; i < SIZE; i++)
			{
				if (unit[i].name == NULL)
					continue;
				if (strcmp(unit[i].name, Delete_name) == 0)
				{
					unit[i].name = NULL;
					unit[i].hp = 0;
					unit[i].mp = 0;
					unit[i].speed = 0;
					unit[i].range = 0;
					unit[i].position = NULL;

					/*for (int j = i+1; j < SIZE; j++)
					{
						unit[i].name = unit[j].name;
						unit[i].hp = unit[j].hp;
						unit[i].mp = unit[j].mp;
						unit[i].speed = unit[j].speed;
						unit[i].range = unit[j].range;
						unit[i].position = unit[j].position;
						i++;
					}
					unit[SIZE - 1].name = NULL;
					unit[SIZE - 1].hp = 0;
					unit[SIZE - 1].mp = 0;
					unit[SIZE - 1].speed = 0;
					unit[SIZE - 1].range = 0;
					unit[SIZE - 1].position = NULL;*/
					printf("\nDelete Data Complete!\n\n");
					break;
				}
			}
			break;
		case 4://Delete All
			printf("DeletePosition input : ");
			scanf("%s", Delete_position);

			for (int i = 0; i < SIZE; i++)
			{
				if (unit[i].name == NULL)
					continue;
				 
				if (strcmp(unit[i].position, Delete_position) == 0)
				{
					unit[i].name = NULL;
					unit[i].hp = 0;
					unit[i].mp = 0;
					unit[i].range = 0;
					unit[i].speed = 0;
					unit[i].position = NULL;
				}
			}
			printf("\nDeletePosition Complete!!\n\n");
			break;
		case 5://PrintAll
			for (int i = 0; i < SIZE; i++)
			{
				printf("\n%d Name : %s\n", count, unit[i].name);
				printf("%d   Hp : %.2lf\n", count, unit[i].hp);
				printf("%d   Mp : %.2lf\n", count, unit[i].mp);
				printf("%d Speed : %d\n", count, unit[i].speed);
				printf("%d Range : %d\n", count, unit[i].range);
				printf("%d Posit : %s\n", count, unit[i].position);
				count++;
			}
			count = 0;
			break;
		case 6://FindMaxHp

			for (int i = 0; i < SIZE; i++)
			{
				if (unit[i].hp > Max_hp)
				{
					Max_hp = unit[i].hp;
					index = i;
				}
			}
			
			printf("\n Name : %s\n", unit[index].name);
			printf("   Hp : %.2lf\n", unit[index].hp);
			printf("   Mp : %.2lf\n", unit[index].mp);
			printf("Speed : %d\n", unit[index].speed);
			printf("Range : %d\n", unit[index].range);
			printf("Posit : %s\n", unit[index].position);

			index = 0;
			Max_hp = 0;
			break;

		case 7://SortByHp
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (unit[i].hp >= unit[j].hp)
					{
						Utemp = unit[i];
						unit[i] = unit[j];
						unit[j] = Utemp;
					}
				}
			}
			printf("\n\nSortByHp Complete!!n\n");
			break;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		free(unit[i].name);
		free(unit[i].position);
	}
	return 0;
}