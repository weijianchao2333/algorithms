#include <stdio.h>

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

void Quick_sort(int * a, int p, int r)
{
	if(p < r)
	{
		int q = Partition(a, p, r);
		Quick_sort(a,p,q-1);
		Quick_sort(a,q+1,r);
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
	int len = 12;
	int a[12] = {13,19,9,5,12,8,7,4,21,2,6,11};
	Quick_sort(a,0,len-1);
	Show(a,len);
	return 0;
}


