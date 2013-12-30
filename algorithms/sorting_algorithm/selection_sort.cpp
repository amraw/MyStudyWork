#include<iostream>

using namespace std;

int main()
{
	int *c,tmp,k,j,smallest,i=0;
	c=new int [100];
	cout<<"Enter the Element:\n";
	cin>>*(c+i);
	while(*(c+i)>=0 && i<100)
	{
		i++;
		cin>>*(c+i);
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
	
	cout<<"Sorted Array:";
	for(j=0;j<i;j++)
	cout<<*(c+j)<<" ";
	cout<<endl;
	delete[] c;
	return 0;
}
