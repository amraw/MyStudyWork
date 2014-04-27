#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> *head;
	head=new list<int>[2];
	head[0].push_back(0);
	head[0].push_back(1);
	head[0].push_back(2);
	head[1].push_back(0);
	head[1].push_back(1);
	head[1].push_back(2);
	list<int>:: iterator i;
	for(int j=0;j<2;j++)
	for(i=head[j].begin();i!=head[j].end();i++)
	cout<<*i<<" ";
	cout<<endl;
	return 0;
}
