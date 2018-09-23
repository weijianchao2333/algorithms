#include <stdio.h>

int Left(int i)
{
	return i << 1;
}

int Right(int i)
{
	return (i << 1) + 1;
}

void Max_heapify(int * a, int i, int size)
{
	int l = Left(i);
	int r = Right(i);
	int largest;
	if(l <= size && a[l] > a[i])
		largest = l;
	else largest = i;
	if(r <= size && a[r] > a[largest])
		largest = r;
	if(largest != i)
	{
	a[i] ^= a[largest];
	a[largest] ^= a[i];
	a[i] ^= a[largest];
	Max_heapify(a,largest,size);
	}
	
	}

void Show(int * a, int size)
{
	int i;
	for(i = 1; i <= size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int size = 14;
	int a[] = {0,27,17,3,16,13,10,1,5,7,12,4,8,9,0};//从下标为1处开始
	Show(a,size);
	Max_heapify(a,3,size);
	Show(a,size);
	return 0;
}



