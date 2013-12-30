#include<iostream>

using namespace std;

void heap_sort(int *c,int start,int end);
void max_heap(int *c,int start,int end);
void heapify(int *c,int i,int end);

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
	
	heap_sort(c,0,i-1);
	cout<<"Array Sorted: ";
	for(j=0;j<i;j++)
	cout<<*(c+j)<<" ";
	cout<<"\n";
	delete[] c;
	return 0;
}

void heap_sort(int *c,int start,int end)
{
	int tmp,i;
	for(i=0;i<end;i++)
	{
		max_heap(c,start,end-i);
		tmp=*c;
		*c=*(c+end-i);
		*(c+end-i)=tmp;
	}
}

void max_heap(int *c,int start,int end)
{
	int i;
	for(i=(end/2);i>=0;i--)
	heapify(c,i,end);
}

void heapify(int *c,int i,int end)
{
	int left,right,large,tmp;
	left=2*i;
	right=2*i+1;
	if(left<=end && *(c+left)>*(c+i))
	large=left;
	else
	large=i;
	if(right<=end && *(c+right)>*(c+large))
	large=right;
	if(large!=i)
	{
		tmp=*(c+i);
		*(c+i)=*(c+large);
		*(c+large)=tmp;
		heapify(c,large,end);
	}
}
