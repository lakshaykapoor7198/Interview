#include <bits/stdc++.h>
using namespace std;
#define V 9

struct Graph{
	int v;
	list < pair<int, int> > *adj;
};

Graph * createNewGraph(){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->v = V;
	graph->adj = new list< pair<int, int> >[V];
	return  graph;
}

void addEdge(Graph *graph, int src, int dest, int weight){
	graph->adj[src].push_back(make_pair(weight, dest));
	graph->adj[dest].push_back(make_pair(weight, src));
}

void dijkstra(Graph *graph , int src){
	int dis[V];
	for (int i=0;i<V;i++){
		dis[i]=INT_MAX;
	}
	dis[0] = 0;
	set < pair <int, int> > s;
	s.insert(make_pair(0,0));
	list < pair<int, int> > :: iterator it;
	while (!s.empty()){
		pair <int, int> min = *(s.begin());
		s.erase(s.begin());
		for (it = graph->adj[min.second].begin();it !=graph->adj[min.second].end();++it){
			if (dis[(*it).second]>dis[min.second]+(*it).first){
				if (dis[(*it).second]!=INT_MAX){
					s.erase(s.find(make_pair(dis[(*it).second], (*it).second)));
				}
				dis[(*it).second]=dis[min.second]+(*it).first;
				s.insert(make_pair(dis[(*it).second], (*it).second))	;
			}
		}
	}

	for (int i=0;i<V;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Graph *graph = createNewGraph();
	addEdge(graph,0, 1, 4);
    addEdge(graph,0, 7, 8);
    addEdge(graph,1, 2, 8);
    addEdge(graph,1, 7, 11);
    addEdge(graph,2, 3, 7);
    addEdge(graph,2, 8, 2);
    addEdge(graph,2, 5, 4);
    addEdge(graph,3, 4, 9);
    addEdge(graph,3, 5, 14);
    addEdge(graph,4, 5, 10);
    addEdge(graph,5, 6, 2);
    addEdge(graph,6, 7, 1);
    addEdge(graph,6, 8, 6);
    addEdge(graph,7, 8, 7);
 	dijkstra(graph, 0);
	return 0;
}