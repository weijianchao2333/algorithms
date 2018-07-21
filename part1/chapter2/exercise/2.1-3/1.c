#include <stdio.h>
#define N 6

int search(int * p, int t, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(p[i] == t)
			return i;
	}
	return -1;
}

int main()
{
	int a[N] = {31, 41, 59, 26, 41, 58};
	int t;
	printf("input a num:\n");
	scanf("%d", &t);
	int ans = search(a,t,N);
	if(ans == -1)
		printf("not found\n");
	else 
		printf("%d\n", ans);
	return 0;
}
