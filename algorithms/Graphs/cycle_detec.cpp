#include<iostream>
#include<list>

using namespace std;

class graph
{
	int v;
	list<int> *adj;
	bool cycleutil(int v,bool *visited,bool *recstack);
	public:
	graph(int V);
	void add_edge(int src,int dest);
	bool cycle_detect();
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

bool graph::cycleutil(int v,bool *visited,bool *recstack)
{
	if(!visited[v])
	{
		visited[v]=true;
		recstack[v]=true;
	}
	list<int> ::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i] && cycleutil(*i,visited,recstack))
		return true;
		if(recstack[*i])
		return true;
	}
	recstack[v]=false;
	return false;
}

bool graph::cycle_detect(void)
{
	bool *visited=new bool[v];
	bool *recstack=new bool[v];
	for(int i=0;i<v;i++)
	visited[i]=recstack[i]=false;
	for(int i=0;i<v;i++)
	if(cycleutil(i,visited,recstack))
	return true;
	return false;
}
int main()
{
    // Create a graph given in the above diagram
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(2, 3);
 
    if(g.cycle_detect())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
    return 0;
}
