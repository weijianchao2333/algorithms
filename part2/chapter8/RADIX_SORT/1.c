#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Counting_sort(int * a, int * b, int k, int len, int * ans)
//内部稳定排序，按数组a来对数组ans排序，结果放在b里
{
	k++;
	int * c = (int *)malloc(sizeof(int)*k);
	int i, j;
	for(i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	for(j = 0; j < len; j++)
	{
		c[a[j]] += 1;
	}
	for(i = 1; i < k; i++)
	{
		c[i] += c[i-1];
	}

	for(j = len-1; j >= 0; j--)
	{
		b[c[a[j]]-1] = ans[j];
		c[a[j]]--;
	}
}

void Radix_sort(int * a, int * b, int k, int len)//基数排序
{
	int i;
	int Max = a[0];
	for(i = 1; i < len; i++)//找最大数
	{
		if(a[i] > Max)
			Max = a[i];
	}
	int count = 1;//循环次数
	while(Max/10!=0)//通过最大数算所需循环次数
	{
		Max/=10;
		count++;
	}
	int p[len];//存放单位数
	int t = 1;
	while(count!=0)
	{
		for(i = 0; i < len; i++)//计算单位数
		{
			p[i] = a[i] % (int)pow(10,t) / pow(10,t-1);
		}
		t++;
		Counting_sort(p,b,k,len,a);//内部稳定排序
		for(i = 0; i < len; i++)
		{
			a[i] = b[i];
		}
		count--;
	}
}


void Show(int * p, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int len = 8;
	int a[] = {12,15,13,0,12,3,0,3};
	int k = 20;
	int b[8];
	Radix_sort(a,b,k,len);
	Show(b,len);
	return 0;
}
