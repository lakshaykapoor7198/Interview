#include <bits/stdc++.h>
using namespace std;


bool findZero(int mat[9][9], int &row, int &col){
	for(int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			if (mat[i][j]==0){
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool isGoodSideWise(int mat[9][9], int row, int col, int num){
	for (int i=0;i<9;i++){
		if (mat[row][i]==num || mat[i][col]==num){
			return false;
		}
	}
	return true;
}

bool isGoodInBox(int mat[9][9], int row, int col, int num){
	for (int i=row/3;i<(row/3)+3;i++){
		for (int j=col/3;j<(col/3)+3;j++){
			if (mat[i][j]==num){
				return false;
			}
		}
	}
	return true;
}

bool isSafe(int mat[9][9], int row, int col, int num){
	if (isGoodSideWise(mat, row, col, num)&&isGoodInBox(mat, row, col, num)){
		return true;
	}
	return false;
}

bool solve(int mat[9][9]){
	int row, col;
	if (!findZero(mat, row, col)) return true;
	for (int i=1;i<=9;i++){
		if (isSafe(mat, row, col, i)){
			mat[row][col] = i;
			if (solve(mat)){
				return true;
			}
			else{
				mat[row][col]=0;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int mat[9][9];
		for (int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				cin>>mat[i][j];
			}
		}
		cout<<solve(mat)<<endl;
	}
	return 0;
}