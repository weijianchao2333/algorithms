#include <stdio.h>
#include <stdlib.h>
int Memoized_cut_rod_aux(int*,int,int*,int*);

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Memoized_cut_rod(int * p, int n)
{
	int * r = (int *)malloc(sizeof(int)*n);
	int * s = (int *)malloc(sizeof(int)*n);
	int i;
	for(i = 0; i <= n; i++)
	{
		r[i] = -999;
	}
	int ans = Memoized_cut_rod_aux(p,n,r,s);
	int t = n;
	while(t>0)
	{
		printf("%d ", s[t]);
		t-=s[t];
	}
	printf("\n");
	return ans;
}

int Memoized_cut_rod_aux(int * p, int n, int * r,int * s)
{
	if(r[n]>=0)//有记录则查找
		return r[n];
	int q;
	if(n == 0)
		q = 0;
	else 
		q = -999;
	int i;
	int t = n < 10 ? n : 10;
	for(i = 1; i <= t; i++)
	{
		int m = p[i]+Memoized_cut_rod_aux(p,n-i,r,s);
		if(q < m)
		{
			q = m;
			s[n] = i;
		}
	}
	r[n] = q;//进行记录
	return q;
}

int main()
{	
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	printf("input n\n");
	scanf("%d", &n);
	int ans = Memoized_cut_rod(p,n);
	printf("ans = %d\n", ans);
}
