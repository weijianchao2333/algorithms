//最好情况O(n^2)
//最坏情况O(n^2)

#include <stdio.h>
#define N 6

void exch(int * u, int * v)
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}

void SelectSort(int * p, int n)
{
	int i, j;
	int t;
	for(i = 0; i < n-1; i++)
	{
		t = i;
		for(j = i+1; j < n; j++)
		{
			if(p[t] > p[j])
				t = j;
		}
		if(t != i)
		{
			exch(&p[t], &p[i]);
		}
	}
}

void Show(int * p , int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
}

int main()
{
	int a[N] = {31, 41, 59, 26, 41, 58};
	SelectSort(a,N);
	Show(a,N);
	return 0;
}
