#include <bits/stdc++.h>
using namespace std;
#define forLoop(i) for (int i=0;i<graph->V;i++)
#define loopFor(i, n) for (int i=0;i<n;i++)

struct Node{
	int data;
	Node *next;
};

struct LinkedList{
	Node *head;
};

struct Graph{
	int V;
	LinkedList *arr;
};

Node * createNewNode(int data){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
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

void addEdge(Graph *graph, int src, int dest){
	Node *node;  
	node= createNewNode(dest);
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

void bfs_queue(Graph *graph, int key){	
	queue <Node *> q;
	bool visited[graph->V];
	int i;
	for (i=0;i<graph->V;i++){
		 visited[i] = false;
	}
	visited[key]=true;
	cout<<key<<" ";
	Node *node;
	do{
		// show(q);
		if (q.empty()){
			node =  graph->arr[key].head;
		}
		else{
			node  =q.front();
			q.pop();
			cout<<node->data<<" ";
			node  =graph->arr[node->data].head;
		}
		while (node){
			if (!visited[node->data]){
				visited[node->data] = true;
				q.push(node);
			}
			node = node->next;
		}

	}while (!q.empty());
	cout<<endl;
}


void dfs_stack(Graph *graph, int key){
	stack <int> s;
	bool visited[graph->V];
	int i;
	for (i=0;i<graph->V;i++){
		 visited[i] = false;
	}
	s.push(key);
	visited[key] = true;
	while(!s.empty()){
		int top = s.top();
		s.pop();
		cout<<top<<" ";
		Node *node = graph->arr[top].head;
		while (node){
			if (!visited[node->data]){
				visited[node->data] = true;
				s.push(node->data);
			}
			node=node->next;
		}
	}
	cout<<endl;
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

void topologicalSort(Graph *graph){
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

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

void allTopologicalSortUtil(Graph *graph,vector <int> &res, int indegree[] , bool visited[]){
	Node *temp;
	int flag=0;
	forLoop(i){
		if (indegree[i]==0 && !visited[i]){
			temp = graph->arr[i].head;
			while (temp){
				indegree[temp->data]--;
				temp = temp->next;
			}
			visited[i] = true;
			res.push_back(i);
			allTopologicalSortUtil(graph,res, indegree, visited);
			visited[i]=false;
			res.pop_back();
			temp = graph->arr[i].head;
			while (temp){
				indegree[temp->data]++;
				temp = temp->next;
			}
			flag=1;
		}
	}
	if (flag==0){
		for (int i=0;i<res.size();i++){
			cout<<res[i]<<" ";
		}

		cout<<endl;
	}
}

void allTopologicalSort(Graph *graph){
	bool visited[graph->V];
	int i,j, indegree[graph->V];
	forLoop(i) visited[i] = false;
	forLoop(i) indegree[i] = 0;

	forLoop(i){
		Node *temp = graph->arr[i].head;
		while (temp){
			indegree[temp->data]++;
			temp = temp->next;
		}
	}
	vector <int> res;
	allTopologicalSortUtil(graph,res, indegree, visited);
}

void kahnTopologicalSort(Graph *graph){
	queue <int> q;
	bool visited[graph->V];
	int i,j, indegree[graph->V];
	forLoop(i) visited[i] = false;
	forLoop(i) indegree[i] = 0;

	forLoop(i){
		Node *temp = graph->arr[i].head;
		while (temp){
			indegree[temp->data]++;
			temp = temp->next;
		}
	}

	do{
		if (!q.empty()){
			int top  =q.front();
			cout<<top<<" ";
			q.pop();
			Node *temp = graph->arr[top].head;
			while (temp){
				indegree[temp->data]--;
				temp = temp->next;
			}	
		}
		forLoop(i){
			if(indegree[i]==0 && !visited[i]){
				q.push(i);
				visited[i]=true;
			}
		}	

	}while(!q.empty());
	cout<<endl;
}

void DFS_UTIL(Graph *graph,int i, bool visited[]){
	visited[i] = true;
	Node *node  =graph->arr[i].head;
	while (node){
		DFS_UTIL(graph, node->data, visited);
		node = node->next;
	}
}

void mother_vertex(Graph *graph){
	bool visited[graph->V];
	int i,v;
	forLoop(i) visited[i] = false;
	forLoop(i){
		if (!visited[i]){
			DFS_UTIL(graph, i, visited);
			v =i;
		}
	}
	forLoop(i) visited[i] = false;
	DFS_UTIL(graph,v, visited);
	forLoop(i){
		if (!visited[i]){
			cout<<-1<<endl;
			return;
		}
	}
	cout<<v<<endl;
}

void Closure_Util(Graph *graph,int s, int v, int res_closure[4][4]){
	res_closure[s][v] = 1;
	Node *node  =graph->arr[v].head;
	while (node){
		if (res_closure[s][node->data]==0){
			Closure_Util(graph,s, node->data, res_closure);	
		}
		node = node->next;
	}
}

void transitive_closure(Graph *graph){
	int res_closure[4][4], i, j;
	memset(res_closure, 0, graph->V*graph->V*sizeof(int));
	forLoop(i){
		Closure_Util(graph,i, i, res_closure);
	}

	forLoop(i){
		forLoop(j){
			cout<<res_closure[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isCyclicUtil(Graph *graph, int i, bool visited[]){
	visited[i] =true;
	Node *node = graph->arr[i].head;
	while (node){
		if (visited[node->data]){
			return true;
		}
		else{
			return isCyclicUtil(graph, node->data, visited);
		}
		node= node->next;
	}
}

bool isCyclic(Graph *graph){
	int v= graph->V;
	bool visited[v];
	loopFor(i, v){
		visited[i] = false;
	}

	loopFor(i,v){
		if (!visited[i]){
			if (isCyclicUtil(graph,i, visited)){
				return true;
			}
		}
	}
	return false;
}


enum Color {WHITE, GRAY, BLACK};

bool isCyclic_Colors_Util(Graph *graph, int i, int colors[]){
	colors[i] = GRAY;
	Node *node  =graph->arr[i].head;
	while (node){
		if (colors[node->data]==WHITE){
			return isCyclic_Colors_Util(graph, node->data, colors);
		}
		if (colors[node->data]==GRAY){
			return true;
		}
		node=node->next;
	}
	colors[i]=BLACK;
	return false;
}

bool isCyclic_Colors(Graph *graph){
	int colors[graph->V];
	loopFor(i, graph->V){
		colors[i]= WHITE;
	}
	
	loopFor(i, graph->V){
		if( colors[i]==WHITE){
			if (isCyclic_Colors_Util(graph, i, colors)){
				return true;
			}
		}
	}
	return false;
}

void countPathsUtil(Graph *graph, int s, int d,int &count, bool visited[]){
	visited[s] = true;
	if (s==d){
		count++;
	}
	else{
		Node *node = graph->arr[s].head;
		while (node){
			if (!visited[node->data]){
				countPathsUtil(graph, node->data, d,count, visited);
			}
			node=node->next;	
		}	
	}
	visited[s]=false;
}

void countPaths(Graph *graph , int s, int d){
	int count=0;
	bool visited[graph->V];
	loopFor(i, graph->V){
		visited[i] = false;
	}
	countPathsUtil(graph,s,d, count,visited);
	cout<<count<<endl;
}


int main(int argc, char const *argv[])
{
	// Graph *graph = createNewGraph(4);
    // addEdge(graph,5, 2);
    // addEdge(graph,5, 0);
    // addEdge(graph,4, 0);
    // addEdge(graph,4, 1);
    // addEdge(graph,2, 3);
    // addEdge(graph,3, 1);
    // printGraph(graph);
    // bfs_queue(graph, 2);
    // dfs_stack(graph, 0);
    // topologicalSort(graph);
    // allTopologicalSort(graph);
    // kahnTopologicalSort(graph);

    // addEdge(graph,0, 1);
    // addEdge(graph,0, 2);
    // addEdge(graph,1, 3);
    // addEdge(graph,4, 1);
    // addEdge(graph,6, 4);
    // addEdge(graph,5, 6);
    // addEdge(graph,5, 2);
    // addEdge(graph,6, 0);
    // mother_vertex(graph);


    // addEdge(graph,0, 1);
    // addEdge(graph,0, 2);
    // addEdge(graph,1, 2);
    // addEdge(graph,2, 0);
    // addEdge(graph,2, 3);
    // addEdge(graph,3, 3);
    // transitive_closure(graph);


    // int k = 3;
    // Graph *graph = createNewGraph(9);
    // addEdge(graph,0, 1);
    // addEdge(graph,0, 2);
    // addEdge(graph,1, 2);
    // addEdge(graph,1, 5);
    // addEdge(graph,2, 3);
    // addEdge(graph,2, 4);
    // addEdge(graph,2, 5);
    // addEdge(graph,2, 6);
    // addEdge(graph,3, 4);
    // addEdge(graph,3, 6);
    // addEdge(graph,3, 7);
    // addEdge(graph,4, 6);
    // addEdge(graph,4, 7);
    // addEdge(graph,5, 6);
    // addEdge(graph,5, 8);
    // addEdge(graph,6, 7);
    // addEdge(graph,6, 8);
    // printKCores(graph, k);


    // Graph *graph  =createNewGraph(4);
    // addEdge(graph,0, 1);
    // addEdge(graph,0, 2);
    // addEdge(graph,1, 2);
    // addEdge(graph,2, 0);
    // addEdge(graph,2, 3);
    // addEdge(graph,3, 3);
 	// cout<<isCyclic(graph)<<endl;
 	// cout<<isCyclic_Colors(graph)<<endl;


 	Graph *graph  =createNewGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 3);
    countPaths(graph,2,3);
	return 0;
}