#include <bits/stdc++.h>
using namespace std;

#define n 8

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool solveKTUtil(int x, int y, int move, int sol[8][8]); 

void solveKT(){
	int sol[n][n];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			sol[i][j]=-1;
		}
	}

	sol[0][0] = 0;
	if (solveKTUtil(0,0,1,sol)==false){
		cout<<"No solution Exist\n";
	}
	else{
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

bool isSafe(int x, int y, int sol[n][n]){
	return (x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1);
}

bool solveKTUtil(int x, int y, int move, int sol[8][8]){
	if (move==n*n){
		return true;
	}

	for (int k=0;k<n;k++){
		int x_new= x+ xMove[k];
		int y_new = y + yMove[k];
		if (isSafe(x_new, y_new, sol)==true){	
			sol[x_new][y_new] = move;
			if (solveKTUtil(x_new, y_new, move+1, sol)==true){
				return true;
			}
			else{
				sol[x_new][y_new] = -1;
			}
		}
	}

	return false;
}


int main(int argc, char const *argv[])
{
	solveKT();
	return 0;
}