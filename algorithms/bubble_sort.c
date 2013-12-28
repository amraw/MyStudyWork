#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *c,tmp,j,key,k,i=0,flag=0;
	c=(int *) calloc(100,sizeof(int));
	printf("Enter the element:\n");
	scanf("%d",(c+i));
	while(*(c+i)>=0 && i<100)
	{
		i++;
		scanf("%d",(c+i));
	}
	for(k=0;k<i;k++)
	{
		for(j=0;j<(i-k-1);j++)
		{
			if(*(c+j) > *(c+j+1))
			{
				flag=1;
				tmp=*(c+j);
				*(c+j)=*(c+j+1);
				*(c+j+1)=tmp;
			}
		}
			if(flag==0)
			break;
			else
			flag=0;
		}
printf("Sorted Array:");
for(j=0;j<i;j++)
printf(" %d ",*(c+j));
printf("\n");
free(c);
return 0;
}
