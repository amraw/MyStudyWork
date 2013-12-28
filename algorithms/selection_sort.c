#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *c,tmp,k,j,smallest,i=0;
	c=(int *)calloc(100,sizeof(int));
	printf("Enter the Element:\n");
	scanf("%d",(c+i));
	while(*(c+i)>=0 && i<100)
	{
		i++;
		scanf("%d",(c+i));
	}
	for(k=0;k<i-1;k++)
	{
		smallest=k;
		for(j=k;j<i;j++)
		if(*(c+smallest)>*(c+j))
		smallest=j;
		tmp=*(c+k);
		*(c+k)=*(c+smallest);
		*(c+smallest)=tmp;
	}
	printf("Sorted Array:");
	for(j=0;j<i;j++)
	printf(" %d ",*(c+j));
	printf("\n");
	free(c);
	return 0;
}
