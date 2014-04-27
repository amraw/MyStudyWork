#include<iostream>
#include<list>
#include<stack>
using namespace std;

class graph{
	int v;
	list<int> *adj;
	void topologicalutil(int v,bool *visited,stack<int> &stack);
	public:
	graph(int v);
	void add_edge(int src,int dest);
	void topologicalsort();
};

graph::graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void graph::add_edge(int src,int dest)
{
	adj[src].push_back(dest);
}

void graph::topologicalutil(int v,bool *visited,stack<int> &stack)
{
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
		topologicalutil(*i,visited,stack);
	}
	stack.push(v);
}

void graph::topologicalsort()
{
	bool *visited=new bool[v];
	stack<int>stack;
	for(int i=0;i<v;i++)
	visited[i]=false;
	for(int i=0;i<v;i++)
	if(!visited[i])
	topologicalutil(i,visited,stack);
	while(!stack.empty())
	{
		cout<<stack.top()<<" ";
		stack.pop();
	}
}

int main()
{
	graph g(6);
	g.add_edge(5,0);
	g.add_edge(5,2);
	g.add_edge(4,0);
	g.add_edge(4,1);
	g.add_edge(2,3);
	g.add_edge(3,1);
	g.topologicalsort();
	return 0;
}
