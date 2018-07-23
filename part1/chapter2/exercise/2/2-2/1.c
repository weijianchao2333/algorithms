#include <stdio.h>

void exch(int *a, int p, int q)
{
	a[p] = a[p] ^ a[q];
	a[q] = a[p] ^ a[q];
	a[p] = a[p] ^ a[q];
}

void BubbleSort(int *a, int n)
{
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		for(j = n-1; j > i; j--)
		{
			if(a[j] < a[j-1])
			{
				exch(a,j,j-1);
			}
		}
	}
}

void Show(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int a[] = {3, 41, 52, 26, 38, 57, 9, 49};
	int len = sizeof(a) / sizeof(int);
	BubbleSort(a,len);
	Show(a,len);
	return 0;
}

//d.冒泡排序，最坏运行时间O(n^2)
