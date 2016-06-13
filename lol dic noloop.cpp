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

void swap(Unit &unit, int len)
{

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
	
	while (1)
	{
		int sel = 0;
		printf("%d", &sel);

		printf("\n(1)Search (2)Insert (3)Delete (4)DeleteAll (5)PrintAll (6)FindMaxHp (7)SortByHp\n Input : ");

		switch (sel)
		{
		case 1://Search
			break;
		case 2://Insert
			break;
		case 3://Delete
			break;
		case 4://DeleteAll
			break;
		case 5://PrintAll
			break;
		case 6://FindMaxHp
			break;
		case 7://SortByHP
			break;
		}
	}
	

	return 0;
}