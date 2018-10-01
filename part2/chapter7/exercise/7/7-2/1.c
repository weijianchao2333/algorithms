#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * Partition(int * a, int p, int r)
{
	int x = a[r];
	int i, j;
	i = p - 1;
	int temp;
	int * c = (int *)malloc(sizeof(int)*2);
	int t = 0;
	for(j = p; j < r; j++)
	{
		if(a[j] == x)
		{
			i+=1;
			t++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else if(a[j] < x)
		{
			i+=1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;

			temp = a[i];
			a[i] = a[i-t];
			a[i-t] = temp;
		}
	}
	temp = a[i+1];
       	a[i+1] = a[r];
	a[r] = temp;
	
	c[0] = i+1-t;
	c[1] = i+1;
	return c;
}

int * Randomized_partition(int * a, int p, int r)
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
		int * q = Randomized_partition(a, p, r);
		Randomized_quick_sort(a,p,q[0]-1);
		Randomized_quick_sort(a,q[1]+1,r);
		free(q);
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
	int a[10] = {3,1,2,4,3,3,2,1,4,4};
	Randomized_quick_sort(a,0,9);
	Show(a,len);
	return 0;
}

//加个变量t来记录重复元素个数，
//1.元素相等时交换一次
//2.元素不等时先交换一次，再根据t再次进行交换








