#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *c,key,j,i=0;
	c=(int *) calloc(100,sizeof(int));
	printf("#####Enter the number & -1 to exit####\n");
	scanf("%d",&key);
	while(key>=0 && i<=100)
	{
		j=i-1;
		while(j>=0 && (key < *(c+j)))
		{
			*(c+j+1)=*(c+j);
			j=j-1;
		}
		*(c+j+1)=key;
		i=i+1;
		scanf("%d",&key);
	}
	printf("Sorted Array:");
	for(j=0;j<i;j++)
	printf(" %d ",*(c+j));
	printf("\n");
	free(c);
	return 0;
}
