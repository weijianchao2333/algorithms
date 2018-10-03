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
	int len = 11;
	int a[] = {6,0,2,0,1,3,4,6,1,3,2};
	int k = 6;
	int b[11];
	Counting_sort(a,b,k,len);
	Show(b,len);
	return 0;
}
