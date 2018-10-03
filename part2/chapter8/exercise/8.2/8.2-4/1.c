#include <stdio.h>
#include <stdlib.h>

int * Counting_sort(int * a, int * b, int k, int len)
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
	/*
	for(j = len-1; j >= 0; j--)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
	*/
	return c;
}

void Count(int n1, int n2, int k, int * a, int * b, int len)
{
	int * c = Counting_sort(a,b,k,len);
	if(n1 > k || n2 < 0)
		printf("%d\n", 0);
	else if(n1 <= 0 && n2 <= k)
		printf("%d\n", c[n2]);
	else if(n2 > k && n1 > 0)
		printf("%d\n", c[k]-c[n1-1]);
	else if(n1 <= 0 && n2 >= k)
		printf("%d\n", c[k]);
	else 
		printf("%d\n", c[n2] - c[n1-1]);

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
	int n1, n2;
	Show(a,len);
	scanf("%d%d",&n1, &n2);
	Count(n1,n2,k,a,b,len);
	return 0;
}
