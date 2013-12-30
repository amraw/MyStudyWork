#include<stdio.h>
#include<stdlib.h>

void heap_sort(int *c,int start,int end);
void max_heap(int *c,int start,int end);
void heapify(int *c,int i,int end);

int main()
{
	int *c,j,i=0;
	c=(int *)calloc(100,sizeof(int));
	printf("Enter the Element:\n");
	scanf("%d",(c+i));
	while(*(c+i)>=0 && i<100)
	{
		i++;
		scanf("%d",(c+i));
	}
	
	heap_sort(c,0,i-1);
	printf("Array Sorted: ");
	for(j=0;j<i;j++)
	printf(" %d ",*(c+j));
	printf("\n");
	free(c);
	return 0;
}

void heap_sort(int *c,int start,int end)
{
	int tmp,i;
	for(i=0;i<end;i++)
	{
		max_heap(c,start,end-i);
		tmp=*c;
		*c=*(c+end-i);
		*(c+end-i)=tmp;
	}
}

void max_heap(int *c,int start,int end)
{
	int i;
	for(i=(end/2);i>=0;i--)
	heapify(c,i,end);
}

void heapify(int *c,int i,int end)
{
	int left,right,large,tmp;
	left=2*i;
	right=2*i+1;
	if(left<=end && *(c+left)>*(c+i))
	large=left;
	else
	large=i;
	if(right<=end && *(c+right)>*(c+large))
	large=right;
	if(large!=i)
	{
		tmp=*(c+i);
		*(c+i)=*(c+large);
		*(c+large)=tmp;
		heapify(c,large,end);
	}
}
