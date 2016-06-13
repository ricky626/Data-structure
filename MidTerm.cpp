#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nodecount = 0;

typedef struct Unit
{
	char* name;
	double hp;
	double mp;
	int speed;
	int range;
	char* position;

}Unit;

typedef struct UnitList
{
	Unit data;
	UnitList* Next;
}UnitList;

typedef struct HEAD
{
	UnitList* head;
}HEAD;

HEAD* Create()
{
	HEAD* List = new HEAD;
	List->head = NULL;
	return List;
}

UnitList* Search(HEAD* List, char str[], int sel)
{
	UnitList* temp = List->head;

	if (temp != NULL)
	{
		do
		{
			if (sel == 1)
			{
				if (strcmp(temp->data.name, str) == 0)
				{
					return temp;
				}
			}
			else if (sel == 2)
			{
				if (strcmp(temp->data.position, str) == 0)
				{
					return temp;
				}
			}

			temp = temp->Next;
		} while (temp != List->head);
	}

	return NULL;
}

void Insert(HEAD* List, Unit data)
{
	if (List->head == NULL)
	{
		List->head = new UnitList;
		List->head->data = data;
		List->head->Next = List->head;
	}

	UnitList* temp = List->head;
	while (temp->Next != List->head)
		temp = temp->Next;

	nodecount++;
	temp->Next = new UnitList;
	temp->Next->data = data;
	temp->Next->Next = List->head;

}

void PrintAll(HEAD* List)
{
	UnitList* temp = List->head;

	if (temp != NULL)
	{
		do
		{
			printf("\nName: %s", temp->data.name);
			printf(" Hp: %.2lf", temp->data.hp);
			printf(" Mp: %.2lf", temp->data.mp);
			printf(" Speed: %d", temp->data.speed);
			printf(" Range: %d", temp->data.range);
			printf(" Pos: %s\n", temp->data.position);

			temp = temp->Next;
		} while (temp != List->head);
	}
	
}

void Delete(HEAD* List, char str[])
{

	while (temp->Next != DeleteNofdr)
		temp = temp->Next;

	temp->Next = DeleteNode->Next;
	nodecount--;

	if (nodecount == 0)
	{
		delete List->head;
		List->head = NULL;
		return;
	}
	delete DeleteNode;
}

void Delete(HEAD* List, char str[])
{



	while (temp->Next != DeleteNode)
		temp = temp->Next;

	temp->Next = DeleteNode->Next;
	nodecount--;

	if (nodecount == 0)
	{
		delete List->head;
		List->head = NULL;
		return;
	}

	delete DeleteNode;
}

void DeleteAll(HEAD* List, char str[])
{
	UnitList* DeleteNode = Search(List, str, 2);
	UnitList* temp = List->head;

	if (DeleteNode == NULL)
		return;

	if (DeleteNode == List->)
	{
		List->head = List->head->Next;
	}

	while (temp->Next != DeleteNode)
		temp = temp->Next;

	temp->Next = DeleteNode->Next;
	nodecount--;

	if (nodecount == 0)
	{
		delete List->head;
		List->head = NULL;
		return;

	}

	delete DeleteNode;
	DeleteAll(List, str);
}

void FindMaxHp(HEAD* List)
{
	UnitList* temp = List->head;
	double Max_hp = 0;

	do
	{
		if (temp->data.hp > Max_hp)
		{
			Max_hp = temp->data.hp;
		}

		temp = temp->Next;
	} while (temp != List->head);

	do
	{
		if (Max_hp == temp->data.hp)
		{
			printf("\nName: %s", temp->data.name);
			printf(" Hp: %.2lf", temp->data.hp);
			printf(" Mp: %.2lf", temp->data.mp);
			printf(" Speed: %d", temp->data.speed);
			printf(" Range: %d", temp->data.range);
			printf(" Pos: %s\n", temp->data.position);
		}
		temp = temp->Next;
	} while (temp != List->head);
}

void SortByHp(HEAD* List)
{
	UnitList* temp = NULL;
	UnitList** unit = new UnitList* [nodecount];

	for (int i = 0; i < nodecount; i++)
	{
		unit[i] = List->head;
		List->head = List->head->Next;
	}

	for (int i = 0; i < nodecount; i++)
	{
		for (int j = i + 1; j < nodecount; j++)
		{
			if (unit[i]->data.hp < unit[j]->data.hp)
			{
				temp = unit[i];
				unit[i] = unit[j];
				unit[j] = temp;
			}
		}
	}

	List->head = unit[0];
	temp = List->head;

	for (int i = 1; i < nodecount; i++)
	{
		temp->Next = unit[i];
		temp = temp->Next;
	}
	temp->Next = List->head;
	
}

int main()
{
	Unit unit[20] = {
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

	HEAD* List = Create();
	UnitList* SearchList = NULL;
	Unit InsertUnit = { 0, };

	for (int i = 0; i < 20; i++)
		Insert(List, unit[i]);
	int sel = 0;
	char name[20] = { 0, };
	char position[20] = { 0, };
	double hp = 0;
	double mp = 0;
	int speed = 0;
	int range = 0;

	while (1)
	{
		printf("\n(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n Input : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1://Search
			printf("Search input : ");
			scanf("%s", name);

			SearchList = Search(List, name, 1);

			if (SearchList != NULL)
			{
				printf("\nName: %s", SearchList->data.name);
				printf(" Hp: %.2lf", SearchList->data.hp);
				printf(" Mp: %.2lf", SearchList->data.mp);
				printf(" Speed: %d", SearchList->data.speed);
				printf(" Range: %d", SearchList->data.range);
				printf(" Pos: %s\n", SearchList->data.position);
			}
			break;
		case 2://Insert
			printf("Name : ");
			scanf("%s", name);
			printf("Hp : ");
			scanf("%lf", &hp);
			printf("Mp : ");
			scanf("%lf", &mp);
			printf("Speed : ");
			scanf("%d", &speed);
			printf("Range : ");
			scanf("%d", &range);
			printf("Positon : ");
			scanf("%s", position);

			InsertUnit.name = (char*)malloc(strlen(name));
			strcpy(InsertUnit.name, name);

			InsertUnit.hp = hp;
			InsertUnit.mp = mp;
			InsertUnit.speed = speed;
			InsertUnit.range = range;

			InsertUnit.position = (char*)malloc(strlen(position));
			strcpy(InsertUnit.position, position);

			Insert(List, InsertUnit);
			break;
		case 3://Delete
			printf("Delete input : ");
			scanf("%s", name);

			Delete(List, name);
			break;
		case 4://DeleteAll
			printf("Position input : ");
			scanf("%s", position);

			DeleteAll(List, position);
			break;
		case 5://PrintAll
			
			PrintAll(List);
			break;
		case 6://FindMaxHp
			FindMaxHp(List);
			break;
		case 7://SortByhp
			SortByHp(List);
			break;
		}
	}
	return 0;
}
