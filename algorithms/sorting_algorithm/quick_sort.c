#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *c,int start,int end);

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
	
	quick_sort(c,0,i-1);
	printf("Array Sorted: ");
	for(j=0;j<i;j++)
	printf(" %d ",*(c+j));
	printf("\n");
	free(c);
	return 0;
}

void quick_sort(int *c,int start,int end)
{
	int j,tmp,i=start;
	if(start<end)
	{
		for(j=start;j<end;j++)
		{
			if(*(c+end)>*(c+j))
			{
				tmp=*(c+j);
				*(c+j)=*(c+i);
				*(c+i)=tmp;
				i++;
			}
		}
	tmp=*(c+i);
	*(c+i)=*(c+end);
	*(c+end)=tmp;
	quick_sort(c,start,i-1);
	quick_sort(c,i+1,end);
}
}
