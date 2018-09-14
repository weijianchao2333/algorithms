#include <stdio.h>
#include <stdlib.h>
#define ROW 2
#define COL 2

int a[ROW][COL];
int b[ROW][COL];
int **c;

typedef struct{
	int row;
	int col;
}subarr;
//用来记录子数组

void Add(int **arr, int **brr, int **temp, subarr t, int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			temp[t.row+i][t.col+j] = arr[i][j] + brr[i][j];
		}
	}
}

int **Multiply(subarr suba, subarr subb, subarr subc, int len)
{
	int n = len;
	int **temp;
	temp = (int **)malloc(sizeof(int *) * n);
	int i;
	for(i = 0; i < n; i++)
	{
		temp[i] = (int *)malloc(sizeof(int) * n);
	}
	if(n == 1)
	{
		temp[0][0] = a[suba.row][suba.col] * b[subb.row][subb.col];
	}
	else
	{
		subarr suba1, suba2, suba3, suba4;
		subarr subb1, subb2, subb3, subb4;
		subarr subc1, subc2, subc3, subc4;

		suba1.row = suba.row;
		suba1.col = suba.col;
		suba2.row = suba.row;
		suba2.col = suba.col + n/2;
		suba3.row = suba.row + n/2;
		suba3.col = suba.col;
		suba4.row = suba.row + n/2;
		suba4.col = suba.col + n/2;

		subb1.row = subb.row;
		subb1.col = subb.col;
		subb2.row = subb.row;
		subb2.col = subb.col + n/2;
		subb3.row = subb.row + n/2;
		subb3.col = subb.col;
		subb4.row = subb.row + n/2;
		subb4.col = subb.col + n/2;

		subc1.row = 0;
		subc1.col = 0;
		subc2.row = 0;
		subc2.col = n/2;
		subc3.row = n/2;
		subc3.col = 0;
		subc4.row = n/2;
		subc4.col = n/2;

		Add(Multiply(suba1, subb1, subc1, n/2), Multiply(suba2, subb3, subc1, n/2), temp, subc1, n/2);
		Add(Multiply(suba1, subb2, subc2, n/2), Multiply(suba2, subb4, subc2, n/2), temp, subc2, n/2);
		Add(Multiply(suba3, subb1, subc3, n/2), Multiply(suba4, subb3, subc3, n/2), temp, subc3, n/2);
		Add(Multiply(suba3, subb2, subc4, n/2), Multiply(suba4, subb4, subc4, n/2), temp, subc4, n/2);

	}
	return temp;
}

void Show()
{

	int i, j;
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int len = ROW;
	int k;
	c = (int **)malloc(sizeof(int *) * len);
	for(k = 0; k < len; k++)
	{
		c[k] = (int *)malloc(sizeof(int) * len);
	}
	int i, j;
	int count = 1;
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			a[i][j] = count;
			b[i][j] = count++;
		}
	}
	subarr suba, subb, subc;
	suba.row = 0;
	suba.col = 0;
	subb.row = 0;
	subb.col = 0;
	subc.row = 0;
	subc.col = 0;
	c = Multiply(suba, subb, subc, len);
	Show();
	return 0;
}
//参考https://blog.csdn.net/u011983557/article/details/51213640 
