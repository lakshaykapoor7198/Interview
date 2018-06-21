#include <bits/stdc++.h>
using namespace std;

int bfsUtil(int *arr, int n, int start, int visited[]){
	queue <int> q;
	q.push(start);
	visited[start] =true;
	int count=0;
	while (!q.empty()){
		int f = q.front();
		q.pop();
		count++;
		for (int i=0;i<n;i++){
			if (!visited[i] && *((arr+f*n)+i)==1){
				visited[i] =true;
				q.push(i);
			}
		}
	}
	return count;
}

int bfs(int *arr, int n){
	int max_till_now=0,in_step;
	int visited[n];
	memset(visited, 0, n*sizeof(visited[0]));
	for (int i=0;i<n;i++){
		if (!visited[i]){
			in_step=bfsUtil(arr, n,i, visited);
			if (in_step>max_till_now) max_till_now=in_step;
		}
	}
	return max_till_now;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n, m;
		cin>>n>>m;
		int bigger = (n>m?n:m);
		int mat[bigger][bigger];
		memset(mat, 0, bigger*bigger*sizeof(mat[0][0]));
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>mat[i][j];
			}
		}
		cout<<bfs(&mat[0][0], bigger)<<endl;
	}
	return 0;
}