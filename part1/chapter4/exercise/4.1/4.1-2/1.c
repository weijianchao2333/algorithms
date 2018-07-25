#include <stdio.h>
#include <limits.h>

struct array{
	int left;
	int right;
	int sum;
};
typedef struct array arr;

arr FindMaxSubarray(int * a, int n)
{
	int i, j;
	int sum, msum;
	arr ans;
	msum = INT_MIN;
	for(i = 0; i < n; i++)
	{
		if(a[i] > msum)
		{
			msum = a[i];
			ans.left = ans.right = i;
			ans.sum = a[i];
		}
		sum = a[i];
		for(j = i + 1; j < n; j++)
		{
			sum += a[j];
			if(sum > msum)
			{
				msum = sum;
				ans.left = i;
				ans.right = j;
				ans.sum = msum;
			}
		}
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
