#include<iostream>
using namespace std;

int main()
{
	int *c,tmp,j,key,k,i=0,flag=0;
	c= new int [100];
	cout<<"Enter the element:\n";
	cin>>(*(c+i));
	while(*(c+i)>=0)
	{
		i++;
		cin>>(*(c+i));
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
cout<<"Sorted Array:";
for(j=0;j<i;j++)
cout<<*(c+j)<<" ";
cout<<endl;
return 0;
}
