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
	UnitList* Prev;
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

	if (nodecount != 0)
	{
		do
		{
			if (sel == 1)
			{
				if (strcmp(temp->data.name, str) == 0)
				{
					return temp;
				}
				else
					temp = temp->Next;
			}
			else if (sel == 2)
			{
				if (strcmp(temp->data.position, str) == 0)
				{
					return temp;
				}
				else
					temp = temp->Next;
			}
		} while (temp != List->head);
	}
	return NULL;
}

void SortByHp(HEAD* List)
{
	UnitList* test = NULL;
	UnitList** unit = new UnitList *[nodecount];

	for (int i = 0; i < nodecount; i++)
	{
		unit[i] = List->head;
		List->head = List->head->Next;
	}
	for (int i = 0; i < nodecount; i++)
	{
		for (int j = i + 1; j < nodecount; j++)
		{
			if (unit[i]->data.hp <  unit[j]->data.hp)
			{
				test = unit[i];
				unit[i] = unit[j];
				unit[j] = test;
			}
		}
	}

	List->head = unit[0];
	test = List->head;
	for (int i = 1; i < nodecount; i++)
	{
		test->Next = unit[i];
		test = test->Next;
	}
	test->Next = List->head;
}

void Insert(HEAD* List, Unit data)
{
	if (List->head == NULL)
	{
		List->head = new UnitList;
		List->head->data = data;
		List->head->Next = List->head;

		nodecount++;
		return;
	}

	UnitList* temp = List->head;

	if (Search(List, data.name, 1) == NULL)
	{
		while (temp->Next != List->head)
			temp = temp->Next;
		
		temp->Next = new UnitList;
		temp->Next->data = data;
		temp->Next->Next = List->head;
		 
		nodecount++;

	}
	else
		return;
}

void Delete(HEAD* List, char str[])
{
	UnitList* DeleteNode = Search(List, str, 1);
	UnitList* temp = List->head; 

	if (DeleteNode == NULL)
		return;

	if (DeleteNode == List->head)
		List->head = List->head->Next;

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

	while (temp->Next != DeleteNode)
		temp = temp->Next;

	temp->Next = DeleteNode->Next;

	if (DeleteNode == List->head)
		List->head = List->head->Next;

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

void PrintAll(HEAD* List)
{
	UnitList* temp = List->head;
	
	/*do
	{
		printf("\n Name : %s ", temp->data.name);
		printf("   Hp : %.2lf ", temp->data.hp);
		printf("   Mp : %.2lf ", temp->data.mp);
		printf("Speed : %d ", temp->data.speed);
		printf("Range : %d ", temp->data.range);
		printf("Posit : %s\n", temp->data.position);

		temp = temp->Prev;

	} while (temp != List->head->Prev);*/

	do 
	{
		if (nodecount != 0)
		{
			printf("\n Name : %s", temp->data.name);
			printf(" Hp : %.2lf", temp->data.hp);
			printf(" Mp : %.2lf", temp->data.mp);
			printf(" Speed : %d", temp->data.speed);
			printf(" Range : %d", temp->data.range);
			printf(" Pos : %s\n", temp->data.position);
			temp = temp->Next;
		}

	} while (temp != List->head);

	
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
		if (temp->data.hp == Max_hp)
		{
			printf("\n Name : %s ", temp->data.name);
			printf("   Hp : %.2lf ", temp->data.hp);
			printf("   Mp : %.2lf ", temp->data.mp);
			printf("Speed : %d ", temp->data.speed);
			printf("Range : %d ", temp->data.range);
			printf("Posit : %s\n", temp->data.position);
		}
		temp = temp->Next;
	} while (temp != List->head);
}
/*
void SortByHp(HEAD* List)
{
	UnitList* temp = List->head;
	Unit unit;

	for (int i = 0; i < nodecount; i++)
	{
		for (int j = 0; j < nodecount; j++)
		{
			if (List->head->data.hp > temp->data.hp)
			{
				unit = List->head->data;
				List->head->data = temp->data;
				temp->data = unit;
			}
			temp = temp->Next;
		}
		List->head = List->head->Next;
	}
}*/ 
   
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
	UnitList* SearchList;
	Unit InsertUnit;

	for (int i = 0; i < 20; i++)
	{
		Insert(List, unit[i]);
	}

	int sel = 0;
	char Search_name[20] = { 0, };
	char Insert_name[20] = { 0, };
	char Delete_name[20] = { 0, };
	char Delete_position[20] = { 0, };
	char Insert_position[20] = { 0, };

	double Insert_hp = 0;
	double Insert_mp = 0;
	int Insert_speed = 0;
	int Insert_range = 0;

	while (1)
	{
		printf("\n(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n Input : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1://Search
			printf("Search input : ");
			scanf("%s", Search_name);

			SearchList = Search(List, Search_name, 1);

			if (SearchList != NULL)
			{
				printf("\n Name : %s\n", SearchList->data.name);
				printf("   Hp : %.2lf\n", SearchList->data.hp);
				printf("   Mp : %.2lf\n", SearchList->data.mp);
				printf("Speed : %d\n", SearchList->data.speed);
				printf("Range : %d\n", SearchList->data.range);
				printf("Posit : %s\n", SearchList->data.position);
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
			printf("Positon : ");
			scanf("%s", Insert_position);

			InsertUnit.name = (char*)malloc(strlen(Insert_name));
			strcpy(InsertUnit.name, Insert_name);

			InsertUnit.hp = Insert_hp;
			InsertUnit.mp = Insert_mp;
			InsertUnit.speed = Insert_speed;
			InsertUnit.range = Insert_range;

			InsertUnit.position = (char*)malloc(strlen(Insert_position));
			strcpy(InsertUnit.position, Insert_position);

			Insert(List, InsertUnit);
			break;
		case 3://Delete
			printf("Delete input : ");
			scanf("%s", Delete_name);

			Delete(List, Delete_name);
			break;
		case 4://DeleteAll
			printf("Position input : ");
			scanf("%s", Delete_position);

			DeleteAll(List, Delete_position);
			break;
		case 5://PrintAll
			PrintAll(List);
			printf("\n%d\n", nodecount);
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
