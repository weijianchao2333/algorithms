//[1->j+1]的子数组必然是:
//1.[1->j]的子数组//我们已经求出来了
//2.子数组[i-j+1]
//这里关键就是第二种情况，所以只要考虑到：如果[1->j]的子数组和<0,那么[1->j+1]的子数组必然不可能是[i->j+1]；还有就是[1-j]的子数组(非最大)一定连续到j
//若[1->j]子数组之和>0则[1->j+1]子数组就加上a[j+1](因为一定连续),否则截断前面的，然后重新开始
//sumarray里保存的是所有连续的和>0的子数组，而因为连续所以也就不一定是[1->j]的最大子数组

#include <stdio.h>

struct array{
	int left;
	int right;
	int sum;
};
typedef struct array arr;

arr FindMaxSubarray(int *a, int n)
{
	int i;
	arr sumarray[n];
	arr ans;
	sumarray[0].left = 0;
        sumarray[0].right = 0;
	sumarray[0].sum = a[0];
	ans = sumarray[0];
	for(i = 1; i < n; i++)
	{
		if(sumarray[i-1].sum < 0)
		{
			sumarray[i].left = i;
			sumarray[i].right = i;
			sumarray[i].sum = a[i];
		}
		else
		{
			sumarray[i].left = sumarray[i-1].left;
			sumarray[i].right = i;
			sumarray[i].sum = sumarray[i-1].sum + a[i];
		}
		if(ans.sum < sumarray[i].sum)
			ans = sumarray[i];
	}
	return ans;
}

int main()
{
	int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int len = sizeof(a) / sizeof(int);
	arr ans = FindMaxSubarray(a,len);
	printf("%d %d %d\n", ans.left+1, ans.right+1, ans.sum);
	return 0;
}
