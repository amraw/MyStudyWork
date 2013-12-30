#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *c,int start, int end);
void merge(int *c,int start,int mid,int end);

int main()
{
	int *c,j,i=0;
	c=(int *)calloc(100,sizeof(int));
	if(c==NULL)
	{
		printf("Memory full\n");
		exit(1);
	}
	printf("Enter the Element:\n");
	scanf("%d",(c+i));
	while(*(c+i)>=0 && i<100)
	{
		i++;
		scanf("%d",(c+i));
	}
	
	merge_sort(c,0,i-1);
	printf("Array Sorted: ");
	for(j=0;j<i;j++)
	printf(" %d ",*(c+j));
	printf("\n");
	free(c);
	return 0;
}

void merge_sort(int *c,int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		merge_sort(c,start,mid);
		merge_sort(c,mid+1,end);
		merge(c,start,mid,end);
	}
	
}

void merge(int *c,int start,int mid,int end)
{
	int i,j,k,m,*l,*r;
	if(start<end)
	{
		l=(int *)calloc((mid-start+1),sizeof(int));
		r=(int *)calloc((end-mid),sizeof(int));
		for(i=start;i<=mid;i++)
		*(l+i-start)=*(c+i);
		for(i=mid+1,j=0;i<=end;i++,j++)
		*(r+j)=*(c+i);
		m=0;k=0;
		for(i=start;i<=end;i++)
		{
			if((*(l+m)<=*(r+k) || k>=j) && (m<=mid))
			{
				*(c+i)=*(l+m);
				m=m+1;
			}
			else
			{
				*(c+i)=*(r+k);
				k=k+1;
			}
		}
	}
	free(l);
	free(r);
}
