#include<iostream>
#include<list>
#include<climits>
using namespace std;

class graph{
	int v;
	list<int> *adj;
	bool iscycleutil(int v,bool *visited,int parent);
	public:
	graph(int V);
	void add_edge(int src,int dest);
	bool iscycle();
};

graph::graph(int V)
{
	v=V;
	adj=new list<int>[v];
}

void graph::add_edge(int src,int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
	
bool graph::iscycleutil(int v,bool *visited,int parent)
{
	visited[v]=true;
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
		{
			if(iscycleutil(*i,visited,v))
			return true;
		}
		else if(*i!=parent)
		return true;
	}
return false;
}

bool graph::iscycle()
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	for(int i=0;i<v;i++)
	if(!visited[i] && iscycleutil(i,visited,-1))
	return true;
	
	return false;
}
	
int main()
{
	graph g1(5);
	g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 0);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    if(g1.iscycle())
    cout<<"Cycle Detected"<<endl;
    else
    cout<<"Cycle not Detecte"<<endl;
    graph g2(3);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.iscycle()?cout<<"Cycle Detected"<<endl:cout<<"Cycle not Detected"<<endl;
    
	return 0;
}
