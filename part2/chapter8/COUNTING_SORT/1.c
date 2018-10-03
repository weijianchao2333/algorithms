#include <stdio.h>
#include <stdlib.h>

void Counting_sort(int * a, int * b, int k, int len)
{
	k++;
	int * c = (int *)malloc(sizeof(int)*k);
	int i, j;
	for(i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	for(j = 0; j < len; j++)
	{
		c[a[j]] += 1;
	}
	for(i = 1; i < k; i++)
	{
		c[i] += c[i-1];
	}

	for(j = len-1; j >= 0; j--)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
}

void Show(int * p, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int len = 8;
	int a[] = {2,5,3,0,2,3,0,3};
	int k = 5;
	int b[8];
	Counting_sort(a,b,k,len);
	Show(b,len);
	return 0;
}
