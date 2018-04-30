#include <bits/stdc++.h>
using namespace std;
#define V 5


void printArray(int arr[V]){
	for (int i=0;i<V;i++) cout<<arr[i]<<" ";
	cout<<endl;
}	

bool isSafe(int x, int y, int graph1[V][V], int visited[V]){
	return (graph1[x][y]==1 && visited[y]==-1);
}

bool checkIntial(int v, int visited[V]){
	for (int i=0;i<V;i++){
		if (visited[i]==0){
			if (i!=v){
				return false;
			}
		}
	}
	return true;
}	

bool solveUtilHamCycle(int v, int move, int total, int graph1[V][V], int visited[V]){
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	printArray(visited);
	cout<<v<<endl;
	if (total==V && checkIntial(v, visited)){
		return true;
	}
	else if (total==V && !checkIntial(v, visited)){
		return false;
	}


	for (int i=0;i<V;i++){
		if (isSafe(v,i,graph1,visited)){
			visited[v] = move;
			if (solveUtilHamCycle(i, move+1, total+1, graph1, visited)){
				return true;
			}
			else{
				visited[v] = -1;
			}
		}
	}

	return false;
}

void hamCycle(int graph1[V][V]){
	int visited[V];
	for (int i=0;i<V;i++){
		visited[i] = -1;
	}
	if (solveUtilHamCycle(0,0,0,graph1,visited)==false){
		cout<<"No Hamiltonian Cycle Exists\n";
	}
	else{
		for (int i=0;i<V;i++){
			cout<<visited[i]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    
    hamCycle(graph1);
 
	return 0;
}