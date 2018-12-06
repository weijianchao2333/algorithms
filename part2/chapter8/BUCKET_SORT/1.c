#include <stdio.h>
#include <stdlib.h>
#define N 20
struct node {
	float key;
	struct node * next;
};
void Bucket_sort(float * a, int len)//桶排序
{
	int i;
	struct node ** b = (struct node **)malloc(sizeof(struct node *) * len);
	//桶初始化
	for(i = 0; i < len; i++)
	{
		b[i] = (struct node *)malloc(sizeof(struct node));
		b[i]->key = -999;
		b[i]->next = NULL;
	}
	//插入数据并排序
	for(i = 0; i < len; i++)
	{
		struct node * p = (struct node *)malloc(sizeof(struct node));
		p->key = a[i];
		p->next = NULL;

		int index = a[i]/10;
		struct node * t = b[index];
		//插入排序
		while((t->next!=NULL)&&(t->next->key <= p->key))
			t = t->next;
		p->next = t->next;
		t->next = p;
	}
	int j = 0;
 	for(i = 0; i < len; i++)//从b中导出数据
	{
		struct node * temp = b[i]->next;
		while(temp != NULL)
		{
			a[j++] = temp->key;
			temp = temp->next;
		}
	}
}

void Show(float * a, int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
		printf("%f ", a[i]);
	printf("\n");
}

int main()
{
	float a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	int len = sizeof(a) / sizeof(float);
	Show(a,len);
	Bucket_sort(a,len);	
	Show(a,len);
	return 0;
}
