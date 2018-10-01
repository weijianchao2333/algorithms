#include <stdio.h>

int Hoare_partition(int * a, int p, int r)
{
	int x = a[p];
	int i = p - 1;
	int j = r + 1;
	while(1)
	{
		do{
			j--;
		}while(a[j] > x);

		do{
			i++;
		}while(a[i] < x);
		if(i < j)
		{
			int temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
			return j;
	}
}

void Quick_sort(int * a, int p, int r)
{
	if(p < r)
	{
		int q = Hoare_partition(a,p,r);
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
	int a[12] = {13,19,9,5,12,8,7,4,11,2,6,21};
	Quick_sort(a,0,11);
	Show(a,len);
	return 0;
}

