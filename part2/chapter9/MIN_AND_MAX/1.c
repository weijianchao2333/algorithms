#include <stdio.h>

void Min_and_max(int * a, int len, int * min, int * max)
{
	int i, temp;
	if(len%2 == 0)
	{
		*min = a[0] < a[1] ? a[0] : a[1];
		*max = a[0] < a[1] ? a[1] : a[0];
		i = 2;
	}
	else 
	{
		*min = *max = a[0];
		i = 1;
	}
	for(; i < len-1; i+=2)
	{
		if(a[i] > a[i+1])
		{
			if(*min > a[i+1])
				*min = a[i+1];
			if(*max < a[i])
				*max = a[i];
		}
		else 
		{
			if(*min > a[i])
				*min = a[i];
			if(*max < a[i+1])
				*max = a[i+1];
		}
	}
}

int main()
{
	int a[10] = {4, 3, 7, 0, 5, 1, 2, 9, 6, 8};
	int min, max;
	Min_and_max(a, 10, &min, &max);
	printf("%d %d\n", min, max);
	return 0;
}
