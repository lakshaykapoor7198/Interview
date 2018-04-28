#include <bits/stdc++.h>
using namespace std;
#define N 4


bool isSafe(int x, int y, int maze[N][N], int visited[N][N]){
	return (x>=0 && x<N && y>=0 && y<N && visited[x][y]==0 && maze[x][y]==1);
}

bool solveMazeUtil(int x, int y, int maze[N][N], int visited[N][N]){
	if (x==N-1 && y==N-1){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++) {
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	if (isSafe(x+1,y,maze,visited)){
		visited[x+1][y] = 1;
		if (solveMazeUtil(x+1, y, maze, visited)==true){
			return true;
		}
		else{
			visited[x+1][y]  = 0;
		}
	}

	if (isSafe(x,y+1,maze,visited)){
		visited[x][y+1] = 1;
		if (solveMazeUtil(x, y+1, maze, visited)==true){
			return true;
		}
		else{
			visited[x][y+1]  = 0;
		}
	}

	return false;

}

void solveMaze(int maze[N][N]){
	int visited[N][N],i,j;
	for (i=0;i<N;i++) for (j=0;j<N;j++) visited[i][j] =0;
	visited[0][0] =1;
	if (solveMazeUtil(0,0,maze,visited)==false){ 
		cout<<"No solution exists\n";
	}
	else{
		for (i=0;i<N;i++){
			for (j=0;j<N;j++) {
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}


int main(int argc, char const *argv[])
{
	int maze[N][N]  =  { {1, 1, 1, 1},
        {1, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1}
    };
 
    solveMaze(maze);
	return 0;
}