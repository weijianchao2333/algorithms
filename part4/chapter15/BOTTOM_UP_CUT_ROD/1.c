#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Bottom_up_cut_rod(int * p, int n)
{
	int * r = (int *)malloc(sizeof(int) * n);
	r[0] = 0;
	int j, q, i;
	for(j = 1; j <= n; j++)
	{
		q = -999;
		for(i = 1; i <= (j < 10 ? j :10); i++)
		{
			q = Max(q,p[i]+r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}

int main()
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	printf("input n\n");
	scanf("%d", &n);
	int ans = Bottom_up_cut_rod(p,n);
	printf("ans = %d\n", ans);
}
