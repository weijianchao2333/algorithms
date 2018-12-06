//1.找n个元素中的最小值,两两比较直至只剩一个元素,同时以此比较来构建二叉树,需要n-1次比较 
//2.找倒数第二小的元素,通过二叉树来查找,这里不好描述，具体看代码,需要ceil[lgn]-1次比较 
//综上，总共需要n+ceil[lgn]-2次比较 

#include <stdio.h>
#include <stdlib.h>
int t = 0;
typedef struct node 
{
	int data;
	struct node * ls, * rs;
}Node;
Node * Find_min(Node * a, int num)//建树
{
	int i, j = 0, k;
	int num2 = num/2;
	Node * temp = (Node *)malloc(sizeof(Node) * num);
	
	for(i = 0; i < num/2*2; i+=2)//以当前层创建上一层
	{
		if(a[i].data < a[i+1].data)
			temp[j].data = a[i].data;
		else 
			temp[j].data = a[i+1].data;
		temp[j].ls = &a[i];
		temp[j].rs = &a[i+1];
		j++;
	}

	if(num%2 != 0)//处理奇数情况
	{
		temp[j].data = a[num-1].data;
		temp[j].ls = NULL;
		temp[j].rs = &a[num-1];
		num2++;
	}
	if(num <= 2)//当前层元素个数为２时，返回
		return &temp[j-1];
	return Find_min(temp, num2);
}

int Find_min2(Node * p)
{
	int min = p->data;
	int min2 = 0x7fffffff;
	while(p->ls != NULL || p->rs != NULL)
	{
		if(p->rs && p->rs->data == min)
		{
			min2 = min2 < p->ls->data ? min2 : p->ls->data;
			p = p->rs;
		}
		else
		{
			if(p->ls)
				min2 = min2 < p->rs->data ? min2 : p->rs->data;
			p = p->ls;
		}
	}
	return min2;
}

int main()
{
	int c[] = {4, 6, 3, 9, 7, 2, 5, 0, 8, 1};
	Node * head;
	int len = sizeof(c) / sizeof(int);
	Node * a = (Node *)malloc(sizeof(Node) * len);
	int i;
	for(i = 0; i < len; i++)
	{
		a[i].data = c[i];
		a[i].ls = a[i].rs = NULL;
	}

	head = Find_min(a, len);
	
	Node * p = head;
	
	int min2 = Find_min2(p);
	
	printf("%d\n", min2);
}
