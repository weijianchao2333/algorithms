#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Counting_sort(int * a, int * b, int k, int len, int * ans)
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
		b[c[a[j]]-1] = ans[j];
		c[a[j]]--;
	}
}

void Radix_sort(int * a, int * b, int k, int len)
{
	int i;
	int Max = a[0];
	for(i = 1; i < len; i++)
	{
		if(a[i] > Max)
			Max = a[i];
	}
	int count = 1;
	while(Max/10!=0)
	{
		Max/=10;
		count++;
	}
	int p[len];
	int t = 1;
	while(count!=0)
	{
		for(i = 0; i < len; i++)
		{
			p[i] = a[i] % (int)pow(10,t) / pow(10,t-1);
			printf("%d ",p[i]);
		}
		printf("\n");
		t++;
		Counting_sort(p,b,k,len,a);
		for(i = 0; i < len; i++)
		{
			a[i] = b[i];
		}
		count--;
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
	int a[] = {12,15,13,0,12,3,0,3};
	int k = 20;
	int b[8];
	Radix_sort(a,b,k,len);
	Show(b,len);
	return 0;
}
