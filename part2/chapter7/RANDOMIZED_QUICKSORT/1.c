#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Partition(int * a, int p, int r)
{
	int x = a[r];
	int i, j;
	i = p - 1;
	int temp;
	for(j = p; j < r; j++)
	{
		if(a[j] <= x)
		{
			i+=1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
       	a[i+1] = a[r];
	a[r] = temp;	
	return i+1;
}

int Randomized_partition(int * a, int p, int r)
{
	srand(time(NULL));
	int i = rand()%(r-p)+p;
	int temp;
	temp = a[i];
	a[i] = a[r];
	a[r] = temp;
	return Partition(a,p,r);
}

void Randomized_quick_sort(int * a, int p, int r)
{
	if(p < r)
	{
		int q = Randomized_partition(a, p, r);
		Randomized_quick_sort(a,p,q-1);
		Randomized_quick_sort(a,q+1,r);
	}
}

void Show(int * a, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int len = 10;
	int a[10] = {4,1,3,2,16,9,10,14,8,7};
	Randomized_quick_sort(a,0,9);
	Show(a,len);
	return 0;
}


