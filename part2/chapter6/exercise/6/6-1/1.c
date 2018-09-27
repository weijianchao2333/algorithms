#include <stdio.h>
#include <limits.h>
#define length 10

int len;

int Parent(int i)
{
	return i/2;
}

void Heap_increase_key(int * a, int key, int i)
{
	if(key < a[i])
		printf("error\n");
	a[i] = key;
	while(i>1 && a[Parent(i)] < a[i])
	{
		a[Parent(i)] ^= a[i];
		a[i] ^= a[Parent(i)];
		a[Parent(i)] ^= a[i];
		i = Parent(i);
	}
}

void Max_heap_insert(int * a, int key)
{
	len++;
	a[len] = INT_MIN;
	Heap_increase_key(a,key,len);
}

void Build_max_heap(int * b, int * a)
{
	len = 1;
	int i;
	for(i = 2; i <= length; i++)
	{
		Max_heap_insert(a,b[i]);
	}
}

void Show(int * a)
{
	int i;
	for(i = 1; i <= len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int b[] = {0,4,1,3,2,16,9,10,14,8,7};
	int a[11];
	a[1] = b[1];
	Build_max_heap(b,a);
	Show(a);
	return 0;
}
