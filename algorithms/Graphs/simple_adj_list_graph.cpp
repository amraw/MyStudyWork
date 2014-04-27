#include<iostream>
#include<list>

using namespace std;

class graph
{
	int v;
	list<int> *adj;
	public:
	graph(int V);
	void add_edge(int src,int dest);
	void print();
};

graph::graph(int V)
{
	v=V;
	adj=new list<int>[V];
}

void graph::add_edge(int src,int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

void graph::print()
{
	list<int>::iterator i;
	for(int j=0;j<v;j++)
	{
		cout<<endl<<"Adjacency list of vertex "<<j;
		cout<<endl<<j;
		for(i=adj[j].begin();i!=adj[j].end();i++)
		{
			int temp=*i;
			cout<<" "<<temp;
		}
	}
}

int main(int argc,char *argv[])
{
	graph gra(5);
	gra.add_edge(0,1);
	gra.add_edge(0,2);
	gra.add_edge(1,2);
	gra.add_edge(1,3);
	gra.add_edge(1,4);
	gra.add_edge(2,3);
	gra.add_edge(3,4);
	gra.print();
	return 0;
}
