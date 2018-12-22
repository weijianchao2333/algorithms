#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Bottom_up_cut_rod(int * p, int n)
{
	int * r = (int *)malloc(sizeof(int) * n);
	int * s = (int *)malloc(sizeof(int) * n);
	r[0] = 0;
	int j, q, i;
	for(j = 1; j <= n; j++)
	{
		q = -999;
		for(i = 1; i <= (j < 10 ? j :10); i++)
		{
			if(q < p[i] + r[j-i]-1)//这里-1,但实际上,例如分成两块只要切一刀,这里却切了两道,所以最后结果输出时补上,没切时的情况也一样
			{
				q = p[i] + r[j-i]-1;
				s[j] = i;
			}
		}
		r[j] = q;
	}
	int c = n;
	while(c > 0)
	{
		printf("%d ", s[c]);
		c = c - s[c];
	}
	printf("\n");
	return r[n];
}

int main()
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	printf("input n\n");
	scanf("%d", &n);
	int ans = Bottom_up_cut_rod(p,n) + 1;//这里+1就是补回来多切的那一刀
	printf("ans = %d\n", ans);
}
//担心自己写错,还网上测了下别人的,答案是一样的,且我的能算10以上的
