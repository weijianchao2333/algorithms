#include <stdio.h>
#include <limits.h>

void InsertionSort(int * p, int a, int b)
{
	int j, i, key;
	for(j = a+1; j <= b; j++)
	{
		key = p[j];
		i = j - 1;
		while(i>=a && p[i] > key)
		{
			p[i+1] = p[i];
			i--;
		}
		p[i+1] = key;
	}
}

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
	int k = 2;//
	if(p < r - k)
	{
		int q = (p+r)/2;
		Mergesort(a,p,q);
		Mergesort(a,q+1,r);
		Merge(a,p,q,r);
	}
	else 
	{
		InsertionSort(a,p,r);
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

//归并排序，当子数组长度小于2时用插排
