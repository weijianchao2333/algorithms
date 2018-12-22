#include <stdio.h>
int fib(int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return 1;
	return fib(n-2) + fib(n-1);
}

int main()
{
	int t;
	scanf("%d", &t);
	int ans = fib(t);
	printf("%d\n", ans);
	return 0;
}
