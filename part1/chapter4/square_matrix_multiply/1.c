#include <stdio.h>
#define n 100

void square_matrix_multiply(int a[][n], int b[][n], int c[][n], int num)
{
	int i, j, k;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			c[i][j] = 0;
			for(k = 0; k < num; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void show(int c[][n], int num)
{
	int i, j;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[n][n];
	int b[n][n];
	int c[n][n];
	int num;
	scanf("%d",&num);
	int i, j;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
			scanf("%d",&a[i][j]);
	}
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
			scanf("%d",&b[i][j]);
	}
	square_matrix_multiply(a,b,c,num);
	show(c,num);
	return 0;
}
