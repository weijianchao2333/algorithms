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
	while(1)
	{
		l = Left(i);
		r = Right(i);
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
			i = largest;
		}
		else
			break;
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
	int a[] = {0,16,4,10,14,7,9,3,2,8,1};//从下标为1处开始
	Show(a,size);
	Max_heapify(a,2,size);
	Show(a,size);
	return 0;
}
