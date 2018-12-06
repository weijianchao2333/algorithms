#include <stdio.h>

int Randomized_partition(int * a, int p, int r)
{
	int x = a[r];
	int i, j;
	i = p - 1;
	int temp;
	for(j = p; j < r; j++)
	{
		if(a[j] <= x)
		{
			i+=1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
       	a[i+1] = a[r];
	a[r] = temp;	
	return i+1;
}


int Randomized_select(int * a, int p, int r, int i)
{
	if(p == r)
		return a[p];
	int q = Randomized_partition(a,p,r);//以当前数组最后一个元素来分割数组
	int k = q-p+1;//当前数组ｋ前都小于a[k]，ｋ后都大于a[k]
	if(i == k)
		return a[q];
	else if(i < k)
		return Randomized_select(a,p,q-1,i);
	else 
		return Randomized_select(a,q+1,r,i-k);//i-k,子数组中相对偏移量
}

int main()
{
	int a[]  = {1, 3, 8, 6, 5, 4, 9, 7, 2, 10};//[1,10]
	int len = sizeof(a)/sizeof(int);
	int ans = Randomized_select(a,0,9,3);
	printf("%d\n", ans);
	return 0;
}
