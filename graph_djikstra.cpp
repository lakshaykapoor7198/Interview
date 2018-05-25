#include <bits/stdc++.h>
using namespace std;

#define forLoop(i) for (int i=0;i<graph->V;i++)
#define loopFor(i, n) for (int i=0;i<n;i++)
#define V 9


struct Node{
	int data;
	int weight;
	Node *next;
};

struct LinkedList{
	Node *head;
};

struct Graph{
	int v;
	LinkedList *arr;
};

Node * createNewNode(int data, int weight){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->weight = weight;
	node->next = NULL;
	return node;
}

Graph * createNewGraph(){
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph->v = V;
	graph->arr = (LinkedList *) malloc(V*sizeof(LinkedList));
	for (int i=0;i<graph->v;i++){
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

	node= createNewNode(src, weight);
	node->next = graph->arr[dest].head;
	graph->arr[dest].head = node;	
}


void printGraph(Graph *graph){
	for (int i=0;i<graph->v; i++){
		Node *temp = graph->arr[i].head;
		while (temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		} 
		cout<<endl;
	}
}


void printArray(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void printPaths(int parent[]){
	int j;
	for (int i=0;i<V;i++){
		j = i;
		while (j!=-1){
			cout<<j<<" ";
			j = parent[j];
		}
		cout<<endl;
	}
}

void dijkstra(int graph[V][V], int src){
	int distance[V], set[V];
	int parent[V];
	for (int i=0;i<V;i++) {
		distance[i]  =INT_MAX;
		set[i] = false;
	} 
	distance[0]=0;
	parent[0] = -1;
	for (int i=0;i<V-1;i++){
		int src; 
		int min =INT_MAX;
		for (int j=0;j<V;j++){
			if (set[j]==false && distance[j]<min){
				src= j;
				min = distance[j];
			}
		}
		set[src] = true;
		for (int k=0;k<V;k++){
			if (graph[src][k]!=0 && !set[k] && distance[k]>distance[src]+graph[src][k]){
				distance[k] = distance[src]+graph[src][k];
				parent[k] = src;
			}
		}
	}

	for (int i=0;i<V;i++){
		cout<<distance[i]<<" ";
	}
	cout<<endl;

	printPaths(parent);
}


struct HeapNode{
	int v;
	int val;
};

struct Heap{
	int capacity;
	int curr;
	struct HeapNode *arr;
};

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	return (i-1)/2;
}

HeapNode getMin(Heap *heap){
	HeapNode h = heap->arr[0];
	return h;
}

Heap *createNewHeap(){
	Heap *heap = (Heap *) malloc(sizeof(Heap));
	heap->capacity = V;
	heap->curr = V;
	heap->arr = (HeapNode *) malloc(V*sizeof(HeapNode));
	return heap; 
}

void swapNodes(HeapNode *a, HeapNode *b){
	HeapNode t = *a;
	*a =*b;
	*b = t;
}

void minHeapify(Heap *heap, int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l<heap->curr && heap->arr[l].val<heap->arr[smallest].val){
		smallest=l;
	}
	if (r<heap->curr && heap->arr[r].val<heap->arr[smallest].val){
		smallest=r;
	}
	
	if (smallest!=i){
		swapNodes(&heap->arr[smallest], &heap->arr[i]);
		minHeapify(heap, smallest);
	}
	
}

HeapNode extractMin(Heap *heap){
	if (heap->curr==1){
		heap->curr--;
		return heap->arr[0];
	}
	HeapNode temp = heap->arr[0];
	swapNodes(&heap->arr[0], &heap->arr[(heap->curr)-1]);
	heap->curr--;

	minHeapify(heap, 0);
	return temp;
}

int isInHeap(Heap *heap, int v){
	for (int i=0;i<heap->curr;i++){
		if (heap->arr[i].v == v){
			return i;
		}
	}
	return -1;
}

bool isHeapEmpty(Heap *heap){
	return (heap->curr==0);
}

void printHeap(Heap *heap){
	cout<<"HEAP PRINT STARTS"<<endl;
	for (int i=0;i<heap->curr;i++){
		cout<<heap->arr[i].v<<" "<<heap->arr[i].val<<endl;
	}
	cout<<"HEAP PRINT STOPS"<<endl;
}

void decreaseKey(Heap *heap, int i, int val){
	heap->arr[i].val = val;
	while (i!=0 && heap->arr[i].val<heap->arr[parent(i)].val){
		swapNodes(&heap->arr[i],&heap->arr[parent(i)]);
		i = parent(i);
	}
}

void dijkstra_list(Graph *graph, int src){
	Heap *heap = createNewHeap();
	for (int i=0;i<V;i++){
		heap->arr[i].val = INT_MAX;
		heap->arr[i].v = i;
	}
	heap->arr[src].val=0;
	swapNodes(&heap->arr[0], &heap->arr[src]);
	// printHeap(heap);
	while(!isHeapEmpty(heap)){
		HeapNode min = extractMin(heap);
		cout<<min.v<<" "<<min.val<<endl;
		Node *node = graph->arr[min.v].head;
		while (node){
			int h =  isInHeap(heap, node->data);
			if (h!=-1 && heap->arr[h].val>min.val+node->weight){
				decreaseKey(heap, h, min.val+node->weight);
			}
			node=node->next;
		}
		// printHeap(heap);
	}

}

int main(int argc, char const *argv[])
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 1, 6},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
	dijkstra(graph,0);


	// Graph* graph = createNewGraph();
 //    addEdge(graph, 0, 1, 4);
 //    addEdge(graph, 0, 7, 8);
 //    addEdge(graph, 1, 2, 8);
 //    addEdge(graph, 1, 7, 11);
 //    addEdge(graph, 2, 3, 7);
 //    addEdge(graph, 2, 8, 2);
 //    addEdge(graph, 2, 5, 4);
 //    addEdge(graph, 3, 4, 9);
 //    addEdge(graph, 3, 5, 14);
 //    addEdge(graph, 4, 5, 10);
 //    addEdge(graph, 5, 6, 2);
 //    addEdge(graph, 6, 7, 1);
 //    addEdge(graph, 6, 8, 6);
 //    addEdge(graph, 7, 8, 7);
 	// dijkstra_list(graph, 0);

	return 0;
}