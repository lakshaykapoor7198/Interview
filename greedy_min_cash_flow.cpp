#include <bits/stdc++.h>
using namespace std;
#define forLoop(i,s, n) for (int i=s;i<n;i++)
#define N 3

struct nodes{
	int v;
	int indegree;
	int has;
	int given;
};

bool myComp(nodes a, nodes b){
	return (a.indegree > b.indegree);
}

void min_cash_flow(int graph[N][N]){
	nodes arr[N];
	forLoop(i, 0, N){	
		arr[i].v=i;
		arr[i].has=0;
		arr[i].given = 0;
		int in = 0;
		forLoop(j, 0, N){
			if (graph[i][j]) in++;
		}
		arr[i].indegree = in;
	}
	sort(arr, arr+N, myComp);
	forLoop(i, 0, N){
		int src = arr[i].v;
		for (dest, 0, N){
			if (graph[src][dest]){
				// if (arr[src].has && arr[src].given==0){
				// 	graph[src][dest]-=arr[src].has;
				// 	arr[dest].has = arr[src].has;
				// 	arr[src].has = 0;
				// }
				else if (arr[src].has==0){
					arr[dest].has = graph[src][dest];
					arr[src].given = graph[src][dest];
					graph[src][dest] = 0;
				}
				else if (arr[src].has==0 && arr[src].given!=0){
					
				}
			}
		} 
	}
}

int main(int argc, char const *argv[])
{
	int graph[N][N] = { {0, 1000, 2000},
    {0, 0, 5000},
    {0, 0, 0} };	
	min_cash_flow(graph);
	return 0;
}