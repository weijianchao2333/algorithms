#include <stdio.h>
#include <limits.h>

void Merge(int *a, int p, int q, int r)
{
	int n1 = q - p + 1;//p->q
	int n2 = r - q;//q+1->r
	int L[n1], R[n2];
	int i, j, k;
	for(i = 0; i < n1; i++)
		L[i] = a[p+i];
	for(j = 0; j < n2; j++)
		R[j] = a[q+j+1];
	i = 0;
	j = 0;
	for(k = p; k <= r; k++)
	{
		if(i == n1)//
		{
			a[k] = R[j];
			j++;
		}
		else if(j == n2)//
		{
			a[k] = L[i];
			i++;
		}
		else if(L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}

void Mergesort(int *a, int p, int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		Mergesort(a,p,q);
		Mergesort(a,q+1,r);
		Merge(a,p,q,r);
	}
}

void Show(int *a, int len)
{
	int i;
	for(i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int a[] = {3, 41, 52, 26, 38, 57, 9, 49};
	int len = sizeof(a) / sizeof(int);
	Mergesort(a,0,len-1);
	Show(a,len);
	return 0;
}
