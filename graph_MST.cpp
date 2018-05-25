#include <bits/stdc++.h>
using namespace std;
#define V 5

void printArray(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void primMST(int graph[V][V]){
	int distance[V], parent[V], mst[V];
	for (int i=0;i<V;i++){
		distance[i] = INT_MAX;
		mst[i] = false;
	}
	distance[0] = 0;
	parent[0]=-1;
	for (int i=0;i<V-1;i++){
		int min = INT_MAX;
		int src = 0;
		for (int j=0;j<V;j++){
			if (mst[j]==false && distance[j]< min){
				src = j;
				min = distance[j];
			}
		}
		mst[src] = true;

		for (int dest = 0;dest<V;dest++){
			if (graph[src][dest]>0 && mst[dest]==false && graph[src][dest]<distance[dest]){
				distance[dest] = graph[src][dest];
				parent[dest] = src;
			}
		}
	}

	for (int i=1;i<V;i++){
		cout<<parent[i]<<"--"<<i<<"  "<<graph[i][parent[i]]<<endl;
	}
}




int main(int argc, char const *argv[])
{
	int graph[V][V] = {{0, 2, 0, 6, 0},
	{2, 0, 3, 8, 5},
	{0, 3, 0, 0, 7},
	{6, 8, 0, 0, 9},
	{0, 5, 7, 9, 0},
	};
	primMST(graph);
	return 0;
}