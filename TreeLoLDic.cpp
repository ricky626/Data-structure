#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

typedef struct Unit
{
	char position[20];
	char name[20];
	int hp;
	int damage;
	int armor;
}Unit;

typedef struct TreeNode
{
	Unit data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* Create(Unit data)
{
	TreeNode* NewNode = new TreeNode;
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->data = data;

	return NewNode;
}

TreeNode* Search(TreeNode* Node, char str[])
{
	if (Node == NULL)
		return NULL;

	if (strcmp(Node->data.name, str) == 0)
		return Node;	
}

void Insert(TreeNode* Node, TreeNode* NewNode)
{
	if (strcmp(NewNode->data.name, Node->data.name) > 0)
	{
		if (Node->left != NULL)
		{
			Insert(Node->left, NewNode);
		}
		else
			Node->left = NewNode;
	}

	else if (strcmp(NewNode->data.name, Node->data.name) < 0)
	{
		if (Node->right != NULL)
		{
			Insert(Node->right, NewNode);
		}
		else
			Node->right = NewNode;
	}

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

	TreeNode* TreeNode;

	for (int i = 0; i < TreeNode)
	return 0;
}