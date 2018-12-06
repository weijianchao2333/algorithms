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
    while(p<r)
	{
		int q = Randomized_partition(a,p,r);
		int k = q-p+1;
		if(i == k)
			return a[q];
		else if(i < k)
		{
			r = q-1;
		}
		else 
		{
			p = q+1;
			i = i-k;
		}
	}
	return a[p];
}

int main()
{
    int a[]  = {1, 3, 8, 6, 5, 4, 9, 7, 2, 10};//[1,10]
    int len = sizeof(a)/sizeof(int);
	int i = 3;
    int ans = Randomized_select(a,0,9,i);
    printf("%d\n", ans);
    return 0;
}
