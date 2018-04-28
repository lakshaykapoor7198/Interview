#include <bits/stdc++.h>
using namespace std;

#define n 4

bool isSafe(int x, int y, int board[n][n]){
	int i,j;
	if (board[x][y]==1) return false;
	
	i=x-1,j=y-1;
	while(i>=0 && j>=0 ){
		if (board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	i=x+1,j=y-1;
	while(i<n && j>=0){
		if (board[i][j]==1){
			return false;
		}
		i++;
		j--;
	}

	j=y-1;
	while(j>=0){
		if (board[x][j]==1){
			return false;
		}
		j--;
	}

	return true;


}

bool solveNQueensUtil(int y, int board[n][n]){
	if (y==n){
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	for (int k=0;k<n;k++){
		if (isSafe(k, y, board)){
			board[k][y] = 1;
			if (solveNQueensUtil(y+1, board)){
				return true;
			}
			else{
				board[k][y] = 0;
			}
		}
	}


	return false;
}


void solveNQueens(){
	int board[n][n];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) board[i][j]=0;
	if (solveNQueensUtil(0,board)==false){
		cout<<"No solution exist\n";
	}
	else{
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	solveNQueens();
	return 0;
}