#include <stdio.h>

int main()
{
	int MAX = 10;

	for (int i = 0; i <= MAX; i++)
	{
		for (int j = 0; j <= MAX; j++)
		{
			for (int k = 0; k <= MAX; k++)
			{
				if (i * j * k == MAX && (i != j || i != k || j != k))
				{
					printf("%d x %d x %d = %d\n", i, j, k, MAX);
				}
				
			}
		}
	}
	return 0;
}