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
		printf("(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n��ɾ� �Է� : ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1://search
			printf("ã���ô� è�Ǿ� : ");
			scanf("%s", search_name);

			for (int i = 0; i < size; i++)
			{
				if (unit[i].name == NULL)
				{
					printf("\nã���ô� ���� ����\n\n");
					break;
				}
				if (strcmp(unit[i].name, search_name) == 0)
				{	
					printf("�̸� : %s\n", unit[i].name);
					printf("ü�� : %.2f\n", unit[i].hp);
					printf("���� : %.2f\n", unit[i].mp);
					printf("�ӵ� : %d\n", unit[i].speed);
					printf("�Ÿ� : %d\n", unit[i].range);
					printf("���� : %s\n\n", unit[i].position);
					break;
				}
			}
			break;

		case 2://insert ���ο� è�Ǿ��� ������ �Է¹޾� �����Ѵ�
			
			printf("new�̸� : ");
			scanf("%s", name);

			printf("newü�� : ");
			scanf("%lf", &hp);
			printf("new���� : ");
			scanf("%lf", &mp);
			printf("new�ӵ� : ");
			scanf("%d", &speed);
			printf("new�Ÿ� : ");
			scanf("%d", &range);

			printf("new���� : ");
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

					printf("\nè�Ǿ����� �Է¿Ϸ�\n\n");
					break;
				}
			}
			break;
		case 3://delete �־��� è�Ǿ� ���� ������ �����Ѵ�
				printf("������ è�Ǿ� : ");
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

						//����
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
						printf("\nè�Ǿ� ������ �����Ϸ�.\n\n");
						
						break;
					}						
				}
			break;
		case 4://delete all �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�
			printf("�������� ���� è�Ǿ� ���� : ");
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
			
			printf("\n�ش��ϴ� è�Ǿ� ���� ���� �Ϸ�\n\n");
			break;
		case 5://PrintAll ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�
			for (int i = 0; i < size; i++)
			{
				printf("%d �̸� : %s\n", count, unit[i].name);
				printf("%d ü�� : %.2f\n", count, unit[i].hp);
				printf("%d ���� : %.2f\n", count, unit[i].mp);
				printf("%d �ӵ� : %d\n", count, unit[i].speed);
				printf("%d �Ÿ� : %d\n", count, unit[i].range);
				printf("%d ���� : %s\n\n", count, unit[i].position);
				count++;
			}
			count = 0;
			break;
		case 6://FindMaxHp ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
			index = 0;
			for (int i = 0; i < size; i++)
			{
				if (unit[i].hp > Max_hp)
				{
					Max_hp = unit[i].hp;
					index = i;
				}
			}
			printf("\n���ϳ��� ü���� ���� è�Ǿ�\n\n");
			printf("�̸� : %s\n", unit[index].name);
			printf("ü�� : %.2f\n", unit[index].hp);
			printf("���� : %.2f\n", unit[index].mp);
			printf("�ӵ� : %d\n", unit[index].speed);
			printf("�Ÿ� : %d\n", unit[index].range);
			printf("���� : %s\n\n", unit[index].position);
			Max_hp = 0;
			break;
		case 7://SortByHp ü���� ū è�Ǿ���� ������� �����Ѵ�.

			for (int i = 0; i < size; i++) �ʱⰪ�� ó�������� ���������(����� ��������) �ݺ����� ����
			{
				for (int j = 0; j < size; j++) �ʱⰪ�� ó�������� ���������(����� ��������) �ݺ����� ����
				{
					if (unit[i].hp >= unit[j].hp) i��尡 1�̸� j��� 0������ ~ ����� �������� hp�� ū�� ��ū�� �˻縦 �Ѵ�.
					{ // ���࿡ ũ��
						Utemp = unit[i]; �ӽ� ��带 �ϳ� �����ؼ� ���� �ٲٴ� �۾��� �Ѵ�.
						unit[i] = unit[j];
						unit[j] = Utemp;
					}
				}
			}
			printf("\n\nü�³��������� ���� �� ����Ϸ�\n\n");
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