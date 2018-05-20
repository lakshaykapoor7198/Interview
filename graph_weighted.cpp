#include <bits/stdc++.h>
using namespace std;
#define forLoop(i) for (int i=0;i<graph->V;i++)


struct Node{
	int data;
	int weight;
	Node *next;
};

struct LinkedList{
	Node *head;
};

struct Graph{
	int V;
	LinkedList *arr;
};

Node * createNewNode(int data, int weight){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->weight = weight;
	node->next = NULL;
	return node;
}

Graph * createNewGraph(int V){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->V = V;
	graph->arr = (LinkedList *) malloc(V*sizeof(LinkedList));
	for (int i=0;i<graph->V;i++){
		graph->arr[i].head = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight){
	Node *node;  
	node= createNewNode(dest,weight);
	node->next = graph->arr[src].head;
	graph->arr[src].head = node;

	//For undirected graph

	// node= createNewNode(src);
	// node->next = graph->arr[dest].head;
	// graph->arr[dest].head = node;	
}

void printArray(int	 arr[], int n){	
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void printGraph(Graph *graph){
	for (int i=0;i<graph->V; i++){
		Node *temp = graph->arr[i].head;
		while (temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		} 
		cout<<endl;
	}
}

void show(queue <Node *> q){
	queue <Node *> q1 = q;
	while (!q1.empty()){
		cout<<q1.front()->data<<" ";
		q1.pop();
	}
	cout<<"\n";
}

void topologicalSortUtil(Graph *graph, int &i, stack <int> &s, vector <bool> &visited){
	Node *node = graph->arr[i].head;
	visited[i] = true;
	while (node){
		if (!visited[node->data]){
			// cout<<i<<" "<<node->data<<endl;
			topologicalSortUtil(graph, node->data, s, visited);
		}
		node = node->next;
	}
	
	s.push(i);
}

int * topologicalSort(Graph *graph){
	stack <int> s;
	vector <bool> visited;
	int i;
	for (i=0; i<graph->V; i++){
		visited.push_back(false);
	}
	for (i=0;i<graph->V;i++){
		if (!visited[i]){
			topologicalSortUtil(graph, i,s, visited);
		}
	}
	int k=0;
	int *topo = new int[graph->V];
	while(!s.empty()){
		topo[k] = s.top();
		k++;
		s.pop();
	}
	return topo;
}


void longestDistance(Graph  *graph, int s){
	int dis[graph->V];
	forLoop(i) dis[i]=INT_MIN;
	dis[s] = 0;
	int *res = topologicalSort(graph);
	int flag =0;
	for (int i=0; i<graph->V;i++){
		if (res[i]==s || flag==1){
			flag=1;
			Node *temp  =  graph->arr[res[i]].head;
			while (temp){
				if (dis[temp->data]<dis[res[i]]+temp->weight){
					dis[temp->data]=dis[res[i]]+temp->weight;
				}
				temp = temp->next;
			}	
		}
	}
	forLoop(i) {
		if (dis[i]==INT_MIN) cout<<"NINF ";
		else cout<<dis[i]<<" ";
	};
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	Graph *graph = createNewGraph(6);
    addEdge(graph,0, 1, 5);
    addEdge(graph,0, 2, 3);
    addEdge(graph,1, 3, 6);
    addEdge(graph,1, 2, 2);
    addEdge(graph,2, 4, 4);
    addEdge(graph,2, 5, 2);
    addEdge(graph,2, 3, 7);
    addEdge(graph,3, 5, 1);
    addEdge(graph,3, 4, -1);
    addEdge(graph,4, 5, -2);
    // printGraph(graph);
    longestDistance(graph, 1);
	return 0;
}