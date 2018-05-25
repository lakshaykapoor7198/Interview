#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest;
};

struct Graph{
	int v, e;
	Edge *edge;
};

Graph * createNewGraph(int v, int e){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->v = v;
	graph->e = e;
	graph->edge = (Edge *)malloc(e*sizeof(Edge));
	return graph;
}

int find(int parent[], int i){
	if (parent[i]==-1){
		return i;
	}
	return find(parent,parent[i]);
}

void Union(int parent[], int x, int y){
	int x1 = find(parent, x);
	int y1 = find(parent, y);
	parent[x] = y;
}

bool isCyclic(Graph *graph){
	int parent[graph->v];
	for (int i=0;i<graph->v;i++){
		parent[i] = -1;
	}

	for (int i=0;i<=graph->e;i++){
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		cout<<x<<" "<<y<<" "<<graph->edge[i].src<<" "<<graph->edge[i].dest<<endl;
		if (x==y){
			return true;
		}
		Union(parent, x, y);
	}
	return false;
}

int main(int argc, char const *argv[])
{
	struct Graph* graph = createNewGraph(3, 2);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    cout<<isCyclic(graph)<<endl;
 
	return 0;
}