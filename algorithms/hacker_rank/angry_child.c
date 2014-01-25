#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge_sort(unsigned int *c,unsigned int start, unsigned int end);
void merge(unsigned int *c,unsigned int start,unsigned int mid,unsigned int end);

int main() {

    unsigned int n,k,*c,i,min,j=0;
    scanf("%d %d",&n,&k);
    c=(unsigned int *)calloc(n,sizeof(unsigned int));
    for(i=0;i<n;i++)
    {
    scanf("%d",c+i);
	}
	merge_sort(c,0,n-1);
	i=0;j=i+k-1;
    min=*(c+j)-*(c+i);
    while(j<n)
    {
           
		if(min > (*(c+j)-*(c+i)))
		min=*(c+j)-*(c+i);
		i++;
		j=i+k-1;
	}
	printf("%d\n",min);
    return 0;
}

void merge_sort(unsigned int *c,unsigned int start,unsigned int end)
{
	unsigned int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		merge_sort(c,start,mid);
		merge_sort(c,mid+1,end);
		merge(c,start,mid,end);
	}
	
}

void merge(unsigned int *c,unsigned int start,unsigned int mid,unsigned int end)
{
	unsigned int i,j,k,m,*l,*r;
	if(start<end)
	{
		l=(unsigned int *)calloc((mid-start+1),sizeof(unsigned int));
		r=(unsigned int *)calloc((end-mid),sizeof(unsigned int));
		for(i=start;i<=mid;i++)
		*(l+i-start)=*(c+i);
		for(i=mid+1,j=0;i<=end;i++,j++)
		*(r+j)=*(c+i);
		m=0;k=0;
		for(i=start;i<=end;i++)
		{
			if((*(l+m)<=*(r+k) || k>=j) && (m<=(mid-start)))
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

