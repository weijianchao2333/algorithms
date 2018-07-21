#include <stdio.h>
#define N 10

int main()
{
	int a[N] = {1, 0, 1, 0, 1, 1, 1, 0, 1, 1};
	int b[N] = {1, 1, 1, 0, 0, 1, 0, 1, 0, 0};
	int ans[N+1];
	int i;
	int c = 0;//进位
	for(i = N-1; i >= 0; i--)
	{
		c += a[i] + b[i];
		if(c == 3)
		{
			ans[i+1] = 1;
			c = 1;
		}
		else if(c == 2)
		{
			ans[i+1] = 0;
			c = 1;
		}
		else 
		{
			ans[i+1] = 1;
			c = 0;
		}
	}
	ans[0] = c;
	
	for(i = 0; i < N+1; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
