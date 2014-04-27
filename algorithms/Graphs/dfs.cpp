#include<iostream>
#include<list>

using namespace std;

class graph
{
	int v;
	list<int> *adj;
	void dfsutil(int v,bool *visited);
	public:
	graph(int V);
	void add_edge(int src,int dest);
	void dfs(int s);
};

graph::graph(int V)
{
	v=V;
	adj=new list<int>[V];
}

void graph::add_edge(int src,int dest)
{
	adj[src].push_back(dest);
}

void graph::dfs(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	dfsutil(s,visited);
	for(int i=0;i<v;i++)
	if(!visited[i])
	dfsutil(i,visited);
}

void graph::dfsutil(int v,bool *visited)
{
	cout<<v<<" ";
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	if(!visited[*i])
	dfsutil(*i,visited);
}

int main()
{
	graph g(6);
	g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,1);
    g.add_edge(3,2);
    g.add_edge(4,3);
    g.add_edge(4,5);
    g.add_edge(5,5);
    g.dfs(0);
	return 0;
}
