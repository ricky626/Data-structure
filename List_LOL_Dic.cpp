#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int nodecount = 0;

typedef struct Unit
{
	char position[10];
	char name[10];
	int hp;
	int damage;
	int armor;
}Unit;

typedef struct UnitList
{
	Unit data;
	UnitList* Next;
	UnitList* Prev;
}UnitList;

typedef struct HEAD
{
	UnitList* Head;
	UnitList* Tail;
}HEAD;

HEAD* Create()
{
	HEAD* List = new HEAD;
	List->Head = NULL;
	return List;
}

UnitList* Search(HEAD* List, char str[], int type)
{
	return NULL;
}
/*
void Insert(HEAD* List, FILE* fp)
{
	UnitList* NewNode = new UnitList;

	fscanf(fp, "%s %s %d %d %d", NewNode->data.position, NewNode->data.name, &NewNode->data.hp, &NewNode->data.damage, &NewNode->data.armor);

	if (List->Head == NULL)
	{
		List->Head = NewNode;
		List->Tail = NewNode;

		NewNode->Next = NULL;

		nodecount++;
		return;
	}

	List->Tail->Next = NewNode;
	NewNode->Next = NULL;
	List->Tail = NewNode;

	nodecount++;
}*/

void Insert(HEAD* List, FILE* fp)
{
	UnitList* NewNode = new UnitList;
	
	fscanf(fp, "%s %s %d %d %d", NewNode->data.position, NewNode->data.name, &NewNode->data.hp, &NewNode->data.damage, &NewNode->data.armor);

	if (List->Head == NULL)
	{
		List->Head = NewNode;
		List->Tail = NewNode;

		NewNode->Prev = NULL;
		NewNode->Next = NULL;
		nodecount++;
		return;
	}

	List->Tail->Next = NewNode;
	NewNode->Next = NULL;
	NewNode->Prev = List->Tail;
	List->Tail = NewNode;
	nodecount++;
}


void FindMaxHp(HEAD* List)
{
	UnitList* temp = List->Head;
	double Max_hp = 0;

	do
	{
		if (temp->data.hp > Max_hp)
		{
			Max_hp = temp->data.hp;
		}
		temp = temp->Next;

	} while (temp != NULL);

	do
	{
		if (temp->data.hp == Max_hp)
		{
			printf("\n Posit : %s", temp->data.position);
			printf(" Name : %s", temp->data.name);
			printf(" Hp : %d", temp->data.hp);
			printf(" Damage : %d", temp->data.damage);
			printf(" Armor : %d", temp->data.armor);			
		}
		temp = temp->Next;
	} while (temp != NULL);
}

void PrintAll(HEAD* List)
{
	UnitList* temp = List->Head;

	if (nodecount != 0)
	{
		do
		{
			printf("\n Posit : %s", temp->data.position);
			printf(" Name : %s", temp->data.name);
			printf(" Hp : %d", temp->data.hp);
			printf(" Damage : %d", temp->data.damage);
			printf(" Armor : %d", temp->data.armor);

			temp = temp->Next;


		} while (temp != List->Tail->Next);
	}
	

}

int main()
{
	/*Unit unit[20] = {
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
	};*/

	UnitList* SearchList;
	Unit InsertUnit;

	char name[20] = { 0, };
	char position[20] = { 0, };
	int hp = 0;
	int damage = 0;
	int armor = 0;
	clock_t start, end;

	HEAD* List = Create();
	FILE* fp = fopen("data.txt", "r");

	for (int i = 0; i < 100; i++)
	{
		Insert(List, fp);
	}

	fclose(fp);

	int sel = 0;

	while (1)
	{
		printf("\n(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n Input : ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:

			break;
		case 2:

			printf("Positon : ");
			scanf("%s", position);

			//InsertUnit.position = (char*)malloc(strlen(position));
			//strcpy(InsertUnit.position, position);

			//InsertUnit.name = (char*)malloc(strlen(name));
			//strcpy(InsertUnit.name, name);


			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			PrintAll(List);
			break;
		case 6:
			FindMaxHp(List);
			break;
		case 7:
			break;
		}

	}
	return 0;
}
