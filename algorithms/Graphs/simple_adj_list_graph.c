#include<stdio.h>
#include<stdlib.h>

struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};

struct adjlist
{
	struct adjlistnode* head;
};

struct graph
{
	int v;
	struct adjlist* array;
};

struct adjlistnode* newadjlistnode(int dest)
{
	struct adjlistnode* newnode=(struct adjlistnode* ) malloc(sizeof(struct adjlistnode));
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}

struct graph* creatgraph(int v)
{
	int i;
	struct graph *gra=(struct graph*)malloc(sizeof(struct graph));
	gra->v=v;
	gra->array=(struct adjlist *)malloc(v*sizeof(struct adjlist));
	for(i=0;i<v;i++)
	gra->array[i].head=NULL;
	return gra;
}

void addEdge(struct graph *gra,int src,int dest)
{
	struct adjlistnode *newnode=newadjlistnode(dest);
	newnode->next=gra->array[src].head;
	gra->array[src].head=newnode;
	newnode=newadjlistnode(src);
	newnode->next=gra->array[dest].head;
	gra->array[dest].head=newnode;
}

void printgraph(struct graph* gra)
{
	int v;
	for(v=0;v<gra->v;v++)
	{
		struct adjlistnode* pcrawl=gra->array[v].head;
		printf("\n Adjacency list for vertec %d",v);
		while(pcrawl)
		{
			printf("->%d",pcrawl->dest);
			pcrawl=pcrawl->next;
		}
		printf("\n");
	
}
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    
    struct graph* gra = creatgraph(V);
    addEdge(gra, 0, 1);
    addEdge(gra, 0, 4);
    addEdge(gra, 1, 2);
    addEdge(gra, 1, 3);
    addEdge(gra, 1, 4);
    addEdge(gra, 2, 3);
    addEdge(gra, 3, 4);
 
    // print the adjacency list representation of the above graph
    printgraph(gra);
 
    return 0;
}
