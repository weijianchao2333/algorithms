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

void Build_max_heap(int * a, int size)
{
	int i;
	for(i = size/2; i >= 1; i--)
		Max_heapify(a,i,size);
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
	int size = 9;
	int a[] = {0,5,3,17,10,84,19,6,22,9};//从下标为1处开始
	Build_max_heap(a,size);
	Show(a,size);
	return 0;
}
