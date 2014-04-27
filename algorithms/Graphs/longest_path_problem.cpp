#include<iostream>
#include<list>
#include<stack>

class adjlistnode{
	int v;
	int weight;
	public:
	adjlistnode(int _v,int _weight)
	{
		v=_v;
		weight=_weight;
	}
	int getv(){return v;}
	int getweight(){return weight;}
};

class graph{
	int vertex;
	list<adjlistnode> *adj;
	public:
	graph(int v){
		vertex=v;
	}
	void add_node(int src,int dest,int weight);
};

void graph::add_node(int src,int dest,int weight)
{
	adjlistnode node(dest,weight);
	adj[src].push_back(node);
}
