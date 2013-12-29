#include<iostream>
using namespace std;

void quick_sort(int *c,int start,int end);

int main()
{
	int *c,j,i=0;
	c=new int [100];
	cout<<"Enter the Element:\n";
	cin>>*(c+i);
	while(*(c+i)>=0 && i<100)
	{
		i++;
		cin>>*(c+i);
	}
	
	quick_sort(c,0,i-1);
	cout<<"Array Sorted: ";
	for(j=0;j<i;j++)
	cout<<*(c+j)<<" ";
	cout<<endl;
	delete[] c; 
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
