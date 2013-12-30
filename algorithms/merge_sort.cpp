#include<iostream>
using namespace std;

void merge_sort(int *c,int start, int end);
void merge(int *c,int start,int mid,int end);

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
	
	merge_sort(c,0,i-1);
	cout<<"Array Sorted: ";
	for(j=0;j<i;j++)
	cout<<*(c+j)<<" ";
	cout<<"\n";
	delete[] c;
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
	int i,j,k,m,n,*l,*r;
	if(start<end)
	{
		l=new int [mid-start+1];
		r=new int [end-mid];
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
	delete[] l;
	delete[] r;
}


