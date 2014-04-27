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
	void bfs(int s);
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

void graph::bfs(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	list<int> queue;
	list<int>::iterator i;
	visited[s]=true;
	queue.push_back(s);
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
	}
}

int main()
{
	graph gra(4);
	gra.add_edge(0,1);
	gra.add_edge(0,2);
	gra.add_edge(2,0);
	gra.add_edge(2,3);
	gra.add_edge(3,3);
	gra.bfs(2);
	cout<<endl;
	return 0;
}
