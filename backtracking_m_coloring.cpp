#include <bits/stdc++.h>
using namespace std;

#define V 4


bool isSafe(int v, int c, int graph[V][V], int colors[V]){
	for (int i=0;i<v;i++){
		if (graph[v][i]==1){
			if (colors[i]==c){
				return false;
			}
		}
	}
	return true;
}

bool solveGraphColoring(int v, int graph[V][V], int colors[V], int num_of_colors){
	if (v==V){
		return true;
	}
	for (int i=1;i<=num_of_colors;i++){
		if (isSafe(v,i,graph, colors)){
			colors[v] = i;
			if (solveGraphColoring(v+1, graph, colors, num_of_colors)){
				return true;
			}
			else{
				colors[v]=0;
			}
		}
	}
	return false;
}

void graphColoring(int graph[V][V], int num_of_colors){
	int colors[V];
	for (int i=0;i<V;i++) colors[i]=0;
	if (solveGraphColoring(0, graph, colors, num_of_colors)==false){
		cout<<"No solution Exists\n";
	}
	else{
		for (int i=0;i<V;i++) cout<<colors[i]<<" ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphColoring (graph, m);
	return 0;
}