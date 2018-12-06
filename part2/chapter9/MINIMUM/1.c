#include <stdio.h>

int Minimum(int * a, int len)
{
	int min = a[0];
	int i;
	for(i = 0; i < len; i++)
	{
		if(min > a[i])
			min = a[i];
	}	
	return min;
}

int main()
{
	int a[10] = {4, 2, 3, 9, 6, 1, 8, 7, 0, 5};
	int min = Minimum(a, 10);
	printf("%d\n", min);
	return 0;
}
