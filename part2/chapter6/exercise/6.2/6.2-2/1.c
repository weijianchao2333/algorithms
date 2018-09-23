#include <stdio.h>

int Left(int i)
{
	return i << 1;
}

int Right(int i)
{
	return (i << 1) + 1;
}

void Min_heapify(int * a, int i, int size)
{
	int l = Left(i);
	int r = Right(i);
	int smallest;
	if(l <= size && a[l] < a[i])
		smallest = l;
	else smallest = i;
	if(r <= size && a[r] < a[smallest])
		smallest = r;
	if(smallest != i)
	{
	a[i] ^= a[smallest];
	a[smallest] ^= a[i];
	a[i] ^= a[smallest];
	Min_heapify(a,smallest,size);
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
	int size = 10;
	int a[] = {0,5,2,4,3,6,7,8,9,11,12};//从下标为1处开始
	Show(a,size);
	Min_heapify(a,1,size);
	Show(a,size);
	return 0;
}
