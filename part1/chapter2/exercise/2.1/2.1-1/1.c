#include <stdio.h>
#define N 6

void InsertionSort(int * p, int n);
void Show(int * p, int n);

void InsertionSort(int * p, int n)
{
	int j, i, key;
	for(j = 1; j < n; j++)
	{
		key = p[j];
		i = j - 1;
		while(i>=0 && p[i] > key)
		{
			p[i+1] = p[i];
			i--;
		}
		p[i+1] = key;
		Show(p,n);
	}
}

void Show(int * p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int a[N] = {31, 41, 59, 26, 41, 58};
	InsertionSort(a,N);
	return 0;
}
