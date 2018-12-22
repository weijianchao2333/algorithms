#include <stdio.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Cut_rod(int * p, int n)
{
	if(n==0)
		return 0;
	int q = -999;
	int i;
	int t = n < 10 ? n : 10;
	for(i = 1; i <= t; i++)//感觉书中i<=n是有问题的,若n>10的话数组p就会越界,因为表格给出最长为10的收益,没有长度超过10所对应的收益
	{
		q = Max(q,p[i]+Cut_rod(p,n-i));
	}
	return q;
}

int main()
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	printf("input n\n");
	scanf("%d", &n);
	int ans = Cut_rod(p,n);
	printf("ans = %d\n", ans);
}
