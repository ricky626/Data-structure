#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//_CRT_SECURE_NO_WARNINGS

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
	Unit unit[21] = {
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
	Unit Utemp;

	int size = 21;

	int sel = 0;
	int count = 0;
	int index = 0;
	
	char search_name[20] = { 0, };
	char delete_name[20] = { 0, };
	char search_pos[20] = { 0, };

	char name[20] = { 0, };
	char position[20] = { 0, };

	double hp = 0;
	double mp = 0;
	int speed = 0;
	int range = 0;
	
	double Max_hp = 0;

	while (1)
	{
		printf("(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n명령어 입력 : ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1://search
			printf("찾으시는 챔피언 : ");
			scanf("%s", search_name);

			for (int i = 0; i < size; i++)
			{
				if (unit[i].name == NULL)
				{
					printf("\n찾으시는 것이 없다\n\n");
					break;
				}
				if (strcmp(unit[i].name, search_name) == 0)
				{	
					printf("이름 : %s\n", unit[i].name);
					printf("체력 : %.2f\n", unit[i].hp);
					printf("마력 : %.2f\n", unit[i].mp);
					printf("속도 : %d\n", unit[i].speed);
					printf("거리 : %d\n", unit[i].range);
					printf("포스 : %s\n\n", unit[i].position);
					break;
				}
			}
			break;

		case 2://insert 새로운 챔피언의 정보를 입력받아 삽입한다
			
			printf("new이름 : ");
			scanf("%s", name);

			printf("new체력 : ");
			scanf("%lf", &hp);
			printf("new마력 : ");
			scanf("%lf", &mp);
			printf("new속도 : ");
			scanf("%d", &speed);
			printf("new거리 : ");
			scanf("%d", &range);

			printf("new포스 : ");
			scanf("%s", position);
			
			for (int i = 0; i < size; i++)
			{
				if (unit[i].name == NULL)
				{
					/*unit[i].name = name;
					unit[i].hp = hp;
					unit[i].mp = mp;
					unit[i].speed = speed;
					unit[i].range = range;
					unit[i].position = position;*/

					unit[i].name = (char*)malloc(strlen(name));
					strcpy(unit[i].name, name);

					unit[i].position = (char*)malloc(strlen(position));
					strcpy(unit[i].position, position);

					unit[i].hp = hp;
					unit[i].mp = mp;
					unit[i].speed = speed;
					unit[i].range = range;

					printf("\n챔피언데이터 입력완료\n\n");
					break;
				}
			}
			break;
		case 3://delete 주어진 챔피언에 대한 정보를 삭제한다
				printf("삭제할 챔피언 : ");
				scanf("%s", delete_name);
				
				for (int i = 0; i < size; i++)
				{
					if (unit[i].name == NULL)
						continue;
					if (strcmp(unit[i].name, delete_name) == 0)
					{
						unit[i].name = NULL;
						unit[i].hp = 0;
						unit[i].mp = 0;
						unit[i].speed = 0;
						unit[i].range = 0;
						unit[i].position = NULL;

						//정렬
						for (int j = i + 1; j < size; j++)
						{
							unit[i].name = unit[j].name;
							
							unit[i].hp = unit[j].hp;
							unit[i].mp = unit[j].mp;
							unit[i].speed = unit[j].speed;
							unit[i].range = unit[j].range;
							unit[i].position = unit[j].position;
							i++;
						}
						unit[size-1].name = NULL;
						unit[size-1].hp = 0;
						unit[size-1].mp = 0;
						unit[size-1].speed = 0;
						unit[size-1].range = 0;
						unit[size-1].position = NULL;
						printf("\n챔피언 데이터 삭제완료.\n\n");
						
						break;
					}						
				}
			break;
		case 4://delete all 주어진 위치의 모든 챔피언 정보를 삭제한다
			printf("포지션을 가진 챔피언 삭제 : ");
			scanf("%s", search_pos);

			for (int i = 0; i < size; i++)	
			{
				if (unit[i].position == NULL || i >= size)
					continue;
				if (strcmp(unit[i].position, search_pos) == 0)
				{
					unit[i].name = NULL;
					unit[i].hp = 0;
					unit[i].mp = 0;
					unit[i].speed = 0;
					unit[i].range = 0;
					unit[i].position = NULL;
				}
			}
			
			printf("\n해당하는 챔피언 정보 삭제 완료\n\n");
			break;
		case 5://PrintAll 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다
			for (int i = 0; i < size; i++)
			{
				printf("%d 이름 : %s\n", count, unit[i].name);
				printf("%d 체력 : %.2f\n", count, unit[i].hp);
				printf("%d 마력 : %.2f\n", count, unit[i].mp);
				printf("%d 속도 : %d\n", count, unit[i].speed);
				printf("%d 거리 : %d\n", count, unit[i].range);
				printf("%d 포스 : %s\n\n", count, unit[i].position);
				count++;
			}
			count = 0;
			break;
		case 6://FindMaxHp 가장 체력이 큰 챔피언의 정보를 출력한다.
			index = 0;
			for (int i = 0; i < size; i++)
			{
				if (unit[i].hp > Max_hp)
				{
					Max_hp = unit[i].hp;
					index = i;
				}
			}
			printf("\n제일높은 체력을 가진 챔피언\n\n");
			printf("이름 : %s\n", unit[index].name);
			printf("체력 : %.2f\n", unit[index].hp);
			printf("마력 : %.2f\n", unit[index].mp);
			printf("속도 : %d\n", unit[index].speed);
			printf("거리 : %d\n", unit[index].range);
			printf("포스 : %s\n\n", unit[index].position);
			Max_hp = 0;
			break;
		case 7://SortByHp 체력이 큰 챔피언부터 순서대로 저장한다.

			for (int i = 0; i < size; i++) 초기값은 처음노드부터 마지막노드(노드의 개수까지) 반복문을 돈다
			{
				for (int j = 0; j < size; j++) 초기값은 처음노드부터 마지막노드(노드의 개수까지) 반복문을 돈다
				{
					if (unit[i].hp >= unit[j].hp) i노드가 1이면 j노드 0번부터 ~ 노드의 개수까지 hp가 큰지 안큰지 검사를 한다.
					{ // 만약에 크면
						Utemp = unit[i]; 임시 노드를 하나 선언해서 값을 바꾸는 작업을 한다.
						unit[i] = unit[j];
						unit[j] = Utemp;
					}
				}
			}
			printf("\n\n체력높은순으로 정렬 및 저장완료\n\n");
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		free(unit[i].name);
		free(unit[i].position);
	}
	return 0;
}