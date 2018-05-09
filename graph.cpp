#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct LinkedList{
	Node *head;
};

struct Graph{
	int v;
	LinkedList *arr;
};

Node * createNewNode(int data){
	Node * node  = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

Graph * createNewGraph(int v){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->v = v;
	graph->arr = (LinkedList *) malloc(v*sizeof(LinkedList));
	for (int i=0;i<v;i++){
		graph->arr[i].head = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int source, int dest){
	Node *node;
	node = createNewNode(dest);
	node->next = graph->arr[source].head;
	graph->arr[source].head = node;

	//for undirected graph
	
	// node = createNewNode(source);
	// node->next = graph->arr[dest].head;
	// graph->arr[dest].head = node;
}


void bfs(Graph *graph, int d){
	bool visited[graph->v];
	for (int i=0;i<graph->v; i++) visited[i] = false;
	queue <Node *> q;
	Node *temp;
	do{
		if (q.empty()){
			temp = graph->arr[d].head;
			while (temp!=NULL){
				q.push(temp);
				temp = temp->next;
			}
		}
		else{
			temp = q.front();
			q.pop();
			visited[temp->data] = true;
			
		}
	}while (!q.empty());
}


void printGraph(Graph *graph){
	for (int i=0;i<graph->v;i++){
		Node *temp  =graph->arr[i].head;
		while (temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	Graph *graph = createNewGraph(4);
	addEdge(graph, 0, 1);
    addEdge(graph,0, 2);
    addEdge(graph,1, 2);
    addEdge(graph,2, 0);
    addEdge(graph,2, 3);
    addEdge(graph,3, 3);
    printGraph(graph);
	return 0;	
}