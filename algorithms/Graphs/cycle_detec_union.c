#include<stdio.h>
#include<stdlib.h>

struct edge{
	int src,dest;
};

struct graph{
	int v,e;
	struct edge *array;
};

void creat_graph(int v,int e,struct graph* g)
{
	g->v=v;
	g->e=e;
	g->array=(struct edge *)malloc(sizeof(struct edge)*e);
};

int findparent(int* parent,int i)
{
	if(parent[i]==-1)
	return i;
	return findparent(parent,parent[i]);
}

void Union(int x,int y,int *parent)
{
	int xset=findparent(parent,x);
	int yset=findparent(parent,y);
	parent[xset]=yset;
}

void add_edge(struct graph *g,int src,int dest,int i)
{
	g->array[i].src=src;
	g->array[i].dest=dest;
}

int iscycle(struct graph *g)
{
	int *parent=(int *)malloc(sizeof(int)*(g->v));
	int i;
	for(i=0;i<g->v;i++)
	parent[i]=-1;
	for(i=0;i<g->e;i++)
	{
		int x=findparent(parent,g->array[i].src);
		int y=findparent(parent,g->array[i].dest);
		if(x==y)
		return 1;
		Union(x,y,parent);
	}
	return 0;
}

int main()
{
	struct graph *g=(struct graph*)malloc(sizeof(struct graph));
	creat_graph(3,3,g);
	add_edge(g,0,1,0);
	add_edge(g,1,2,1);
	add_edge(g,2,0,2);
	if(iscycle(g))
	printf("Cycle is detected\n");
	else
	printf("Cycle is not detected\n");
	return 0;
}
