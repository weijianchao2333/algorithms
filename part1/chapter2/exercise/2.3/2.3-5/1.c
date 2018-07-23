#include <stdio.h>
#include <stdbool.h>

int BinarySearch(int *a, int p, int r, int t)
{
	if(p <= r)
	{
		int q = (p+r)/2;
		if(t == a[q])
		{
			return 1;
		}
		else if(t < a[q])
			return BinarySearch(a,p,q-1,t);
		else	 
			return BinarySearch(a,q+1,r,t);
	}
	else
	{
		return -1;
	}
}

int main()
{
	int a[] = {3, 9, 26, 38, 41, 49, 52, 57};
	int t;
	printf("input a num:\n");
	scanf("%d", &t);
	int len = sizeof(a) / sizeof(int);
	int ans = BinarySearch(a, 0, len-1, t);
	if(ans == 1)
		printf("find\n");
	else 
		printf("not find\n");
	return 0;
}
// T(n) = T(n/2) + c
