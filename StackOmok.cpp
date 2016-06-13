#include <stdio.h>
#include <Windows.h>

#define MAX 20

typedef struct Stone
{
	int x;
	int y;
	int type;

}Stone;

typedef struct Node
{
	Stone stone;
	Node* pNext;
}Node;

Node* head = NULL;
Node* temp = NULL;
int count = 0;
int Undo = 0;

//Stone data = { 0, };


void Push(int x, int y, int type)
{
	Node* NewNode = new Node;

	NewNode->stone.x = x;
	NewNode->stone.y = y;
	NewNode->stone.type = type;
	count++;

	if (head == NULL)
	{
		head = NewNode;
		return;
	}
	else
	{
		NewNode->pNext = head;
		head = NewNode;
		return;
	}
}

void mPush()
{
	Node* NewNode = new Node;

	NewNode->stone.x = temp->stone.x;
	NewNode->stone.y = temp->stone.y;
	NewNode->stone.type = temp->stone.type;

	NewNode->pNext = head;
	head = NewNode;
	Undo--;
	count++;


}

void Pop()
{
	Node* DeleteNode = head;
	Node* tempNode = new Node;
	//Stone stone = head->stone;

	//data = DeleteNode->stone;

	//if (head == NULL)
	//	return;

	if (temp == NULL)
		temp = tempNode;
	else
	{
		tempNode->pNext = temp;
		temp = tempNode;
	}

	temp->stone.x = head->stone.x;
	temp->stone.y = head->stone.y;
	temp->stone.type = head->stone.type;

	head = head->pNext;
	delete DeleteNode;
	count--;
	Undo++;

	//return stone;
}

int main()
{
	char* board[MAX][MAX] = { 0, };
	int check = 1;
	int b_count = 0, w_count = 0;
	int x = 0, y = 0;
	int sel = 0;
	int d_check[MAX][MAX] = { 0, };


	while (1)
	{
		system("cls");

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (d_check[i][j] == 2)
					board[i][j] = "��";
				else if (d_check[i][j] == 1)
					board[i][j] = "��";
				else if (d_check[i][j] == 0)
					board[i][j] = "��";

				printf("%s", board[i][j]);
			}
			printf("\n");
		}


		printf("\n������ : %d��  �Ͼᵹ : %d��\n", b_count, w_count);
		printf("��ɾ� �Է� : (1. ������ 2. ������ 3. ��������� 4. ���� 5. �ҷ�����) : ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
		{
			printf("��ǥ �Է� : ");
			scanf_s("%d %d", &x, &y);

			if (x < MAX && y < MAX && x > -1 && y > -1)
			{
				if (check == 1 && d_check[y][x] != 1 && d_check[y][x] != 2) //������
				{
					check = 2; //�򵹷�
					b_count++;

					d_check[y][x] = 1;
					Push(x, y, check);

				}
				else if (check == 2 && d_check[y][x] != 1 && d_check[y][x] != 2) //��
				{
					check = 1; //��������
					w_count++;

					d_check[y][x] = 2;
					Push(x, y, check);
				}
			}
		}

		break;

		case 2: //������
		{
			//Stone temp = Pop();
			if (count != 0)
			{
				Pop();
				d_check[temp->stone.y][temp->stone.x] = 0;

				if (check == 1)
				{
					check = 2;
					w_count--;
				}

				else
				{
					check = 1;
					b_count--;
				}
			}
		

		}
		break;

		case 3: //������ ���
		{
			//Push(data.x, data.y, check);
			if (Undo > 0)
			{
				mPush();

				d_check[temp->stone.y][temp->stone.x] = check;
				temp = temp->pNext;

				if (check == 1)
				{
					check = 2;
					b_count++;
				}

				else
				{
					check = 1;
					w_count++;
				}
			}
			
			
		}
		break;

		case 4: //����
		{
			FILE* f = fopen("Omok.txt", "w+");

			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					fprintf(f, "%1d", d_check[i][j]);
				}
				fprintf(f, "\n");
			}

			fclose(f);

		}
		break;

		case 5: //�ҷ�����
		{
			FILE* fp = fopen("Omok.txt", "r");
			
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					fscanf(fp, "%1d", &d_check[i][j]);
				}
				fscanf(fp, "\n");
			}
			fclose(fp);
		}
		break;

		default:
			break;
		}

	}
	return 0;
}