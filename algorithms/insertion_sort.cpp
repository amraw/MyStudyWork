#include<iostream>
using namespace std;

int main()
{
	int *c,key,j,i=0;
	c= new int [100];
	cout<<"#####Enter the number & -1 to exit####\n";
	cin>>key;
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
		cin>>key;
	}
	cout<<"Sorted Array:";
	for(j=0;j<i;j++)
	cout<<(*(c+j))<<" ";
	cout<<"\n";
	delete[] c;
	return 0;

}
