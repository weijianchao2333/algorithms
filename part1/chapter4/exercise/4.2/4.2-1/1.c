#include <stdio.h>
#include <stdlib.h>
#define ROW 2
#define COL 2

int **a;
int **b;
int **c;

typedef struct{
	int row;
	int col;
}subarr;

void Add(subarr t1, subarr t2, subarr t3, int ** p1, int ** p2, int ** temp, int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			temp[t3.row+i][t3.col+j] = p1[t1.row+i][t1.col+j] + p2[t2.row+i][t2.col+j];
		}
	}
}

void Sub(subarr t1, subarr t2, subarr t3, int ** p1, int ** p2, int ** temp, int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			temp[t3.row+i][t3.col+j] = p1[t1.row+i][t1.col+j] - p2[t2.row+i][t2.col+j];
		}
	}
}

int ** Multiply(int ** ka, int ** kb, subarr suba, subarr subb, subarr subc, int len)
{
	int n = len;
	int ** temp;
	int i;
	temp = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++)
		temp[i] = (int *)malloc(sizeof(int) * n);

	if(n == 1)
	{
		temp[0][0] = ka[suba.row][suba.col] * kb[subb.row][subb.col];
	}
	else
	{

		subarr suba1, suba2, suba3, suba4;
		subarr subb1, subb2, subb3, subb4;
		subarr subc1, subc2, subc3, subc4;

		suba1.row = suba.row;
		suba1.col = suba.col;
		suba2.row = suba.row;
		suba2.col = suba.col + n/2;
		suba3.row = suba.row + n/2;
		suba3.col = suba.col;
		suba4.row = suba.row + n/2;
		suba4.col = suba.col + n/2;

		subb1.row = subb.row;
		subb1.col = subb.col;
		subb2.row = subb.row;
		subb2.col = subb.col + n/2;
		subb3.row = subb.row + n/2;
		subb3.col = subb.col;
		subb4.row = subb.row + n/2;
		subb4.col = subb.col + n/2;

		subc1.row = 0;
		subc1.col = 0;
		subc2.row = 0;
		subc2.col = n/2;
		subc3.row = n/2;
		subc3.col = 0;
		subc4.row = n/2;
		subc4.col = n/2;

		int ** s1, ** s2, ** s3, ** s4, ** s5, ** s6, ** s7, ** s8, ** s9, ** s10;
		int n2 = n/2;
		s1 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s1[i] = (int *)malloc(sizeof(int) * n2);
		s2 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s2[i] = (int *)malloc(sizeof(int) * n2);
		s3 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s3[i] = (int *)malloc(sizeof(int) * n2);
		s4 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s4[i] = (int *)malloc(sizeof(int) * n2);
		s5 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s5[i] = (int *)malloc(sizeof(int) * n2);
		s6 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s6[i] = (int *)malloc(sizeof(int) * n2);
		s7 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s7[i] = (int *)malloc(sizeof(int) * n2);
		s8 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s8[i] = (int *)malloc(sizeof(int) * n2);
		s9 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s9[i] = (int *)malloc(sizeof(int) * n2);
		s10 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			s10[i] = (int *)malloc(sizeof(int) * n2);
		
		subarr subt;
		subt.row = subt.col = 0;

		Sub(subb2,subb4,subt,b,b,s1,n2);
		Add(suba1,suba2,subt,a,a,s2,n2);
		Add(suba3,suba4,subt,a,a,s3,n2);
		Sub(subb3,subb1,subt,b,b,s4,n2);
		Add(suba1,suba4,subt,a,a,s5,n2);
		Add(subb1,subb4,subt,b,b,s6,n2);
		Sub(suba2,suba4,subt,a,a,s7,n2);
		Add(subb3,subb4,subt,b,b,s8,n2);
		Sub(suba1,suba3,subt,a,a,s9,n2);
		Add(subb1,subb2,subt,b,b,s10,n2);

		int ** p1, ** p2, ** p3, ** p4, ** p5, ** p6, ** p7;
		p1 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p1[i] = (int *)malloc(sizeof(int) * n2);
		p2 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p2[i] = (int *)malloc(sizeof(int) * n2);
		p3 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p3[i] = (int *)malloc(sizeof(int) * n2);
		p4 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p4[i] = (int *)malloc(sizeof(int) * n2);
		p5 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p5[i] = (int *)malloc(sizeof(int) * n2);
		p6 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p6[i] = (int *)malloc(sizeof(int) * n2);
		p7 = (int **)malloc(sizeof(int *) * n2);
		for(i = 0; i < n2; i++)
			p7[i] = (int *)malloc(sizeof(int) * n2);
		
		p1 = Multiply(a,s1,suba1,subt,subt,n2);
		p2 = Multiply(s2,b,subt,subb4,subt,n2);
		p3 = Multiply(s3,b,subt,subb1,subt,n2);
		p4 = Multiply(a,s4,suba4,subt,subt,n2);
		p5 = Multiply(s5,s6,subt,subt,subt,n2);
		p6 = Multiply(s7,s8,subt,subt,subt,n2);
		p7 = Multiply(s9,s10,subt,subt,subt,n2);

		Add(subt,subt,subc1,p5,p4,temp,n2);
		Sub(subc1,subt,subc1,temp,p2,temp,n2);
		Add(subc1,subt,subc1,temp,p6,temp,n2);

		Add(subt,subt,subc2,p1,p2,temp,n2);

		Add(subt,subt,subc3,p3,p4,temp,n2);

		Add(subt,subt,subc4,p5,p1,temp,n2);
		Sub(subc4,subt,subc4,temp,p3,temp,n2);
		Sub(subc4,subt,subc4,temp,p7,temp,n2);
	}
	return temp;
}

int main()
{
	int i, j;
	int len = ROW;
	int k;
	a = (int **)malloc(sizeof(int*)*len);
	for(k = 0; k < len; k++)
		a[k] = (int*)malloc(sizeof(int)*len);
	b = (int **)malloc(sizeof(int*)*len);
	for(k = 0; k < len; k++)
		b[k] = (int*)malloc(sizeof(int)*len);
	c = (int **)malloc(sizeof(int*)*len);
	for(k = 0; k < len; k++)
		c[k] = (int*)malloc(sizeof(int)*len);
	
	a[0][0] = 1;
	a[0][1] = 3;
	a[1][0] = 7;
	a[1][1] = 5;
	b[0][0] = 6;
	b[0][1] = 8;
	b[1][0] = 4;
	b[1][1] = 2;

	subarr suba, subb, subc;
	suba.row = suba.col = 0;
	subb.row = subb.col = 0;
	subc.row = subc.col = 0;

	c = Multiply(a,b,suba,subb,subc,len);
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}








