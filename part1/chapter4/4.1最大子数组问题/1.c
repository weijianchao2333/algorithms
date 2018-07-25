#include <stdio.h>
#include <limits.h>

struct array
{
	int left;
	int right;
	int sum;
};
typedef struct array arr; 

arr FindMaxCrossingSubarray(int *a, int low, int mid, int high)
{
	int i, j;
	int lpos, rpos;
	int t = 0;
	int lsum = INT_MIN, rsum = INT_MIN, sum = 0;
	for(i = mid; i >= low; i--)
	{
		t+=a[i];
		if(t > lsum)
		{
			lsum = t;
			lpos = i;
		}
	}
	t = 0;
	for(j = mid + 1; j <= high; j++)
	{
		t+=a[j];
		if(t > rsum)
		{
			rsum = t;
			rpos = j;
		}
	}
	sum = lsum + rsum;
	arr ans = {lpos, rpos, sum};
	return ans;
}

arr FindMaxSubarray(int * a, int low, int high)
{
	if(low == high)
	{
		arr a1 = {low,high,a[low]};
		return a1;
	}
	else
	{
		int mid = (low + high) / 2;
		arr a2 = FindMaxSubarray(a,low,mid);
		arr a3 = FindMaxSubarray(a,mid+1,high);
		arr a4 = FindMaxCrossingSubarray(a,low,mid,high);

		if(a2.sum >= a3.sum && a2.sum >= a4.sum)
			return a2;
		else if(a3.sum >= a2.sum && a3.sum >= a4.sum)
			return a3;
		else 
			return a4;
	}
}

int main()
{
	int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int len = sizeof(a) / sizeof(int);
	arr ans = FindMaxSubarray(a,0,len-1);
	printf("%d %d %d\n", ans.left+1, ans.right+1, ans.sum);
	return 0;
}
