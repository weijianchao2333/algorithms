#include <stdio.h>
#define N 6

void InsertionSort(int * p, int n);
void Show(int * p, int n);
int search(int * p, int a, int c, int t);

void InsertionSort(int * p, int n)
{
	int j, i, key;
	for(j = 1; j < n; j++)
	{
		key = p[j];
		i = j - 1;
		int t = search(p,0,i,key);
		while(i>=t && p[i] > key)
		{
			p[i+1] = p[i];
			i--;
		}
		p[i+1] = key;//i+1=t
	}
}

//用来找比key大的数中最小的那个
int search(int * p, int a, int c, int t)
{
	int b = (a+c)/2;
	//判断两个端点的边界情况
	if(p[a] >= t)
		return a;
	if(p[c] <= t)
		return c+1;
	//一般情况
	if(p[b] <= t && p[b+1] >= t)
	{
		return b+1;
	}
	else if(p[b] < t)
	{
		return search(p,b+1,c,t);
	}
	else if(p[b] > t)
	{
		return search(p,a,b-1,t);
	}
}
void Show(int * p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int a[N] = {31, 41, 59, 26, 41, 58};
	InsertionSort(a,N);
	Show(a,N);
	return 0;
}
