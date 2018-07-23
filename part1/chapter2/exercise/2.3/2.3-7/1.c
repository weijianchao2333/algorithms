//先把数组排下序，然后对每一个小于t/2的数c，在数组中二分查找找t-c

#include <stdio.h>
#include <limits.h>

void Merge(int *a, int p, int q, int r)
{
	int n1 = q - p + 1;//p->q
	int n2 = r - q;//q+1->r
	int L[n1+1], R[n2+1];
	int i, j, k;
	for(i = 0; i < n1; i++)
		L[i] = a[p+i];
	for(j = 0; j < n2; j++)
		R[j] = a[q+j+1];
	
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for(k = p; k <= r; k++)
	{
		if(L[i] < R[j])
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

int BinarySearch(int *a, int p, int r, int t)
{
	if(p <= r)
	{
		int q = (p+r)/2;
		if(t == a[q])
		{
			return 1;
		}
		else if(t < a[q])
			return BinarySearch(a,p,q-1,t);
		else	 
			return BinarySearch(a,q+1,r,t);
	}
	else
	{
		return -1;
	}
}

int main()
{
	int a[] = {1, 3, 6, 2, 8, 4, 3, 0};
	int t = 6;
	int len = sizeof(a) / sizeof(int);
	Mergesort(a, 0, len-1);
	for(int i = 0; i <= t/2; i++)
	{
		if(BinarySearch(a,0,len-1,t-a[i]))
			printf("%d,%d\n", a[i], t-a[i]);

	}
	return 0;
}
