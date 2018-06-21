#include <bits/stdc++.h>
using namespace std;

bool winBoth(int board[3][3]){
	int win[2]={0,0};
	int n=3;
	if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
		win[board[1][1]]+=1;
	}
	else if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){
		win[board[1][1]]+=1;
	}
	if (win[0]>0) return true;
	for (int i=0;i<n;i++){
		if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
			win[board[i][0]]+=1;
		}
		if (board[0][i]==board[1][i] && board[1][i]==board[2][i]){
			win[board[0][i]]+=1;
		}
	}
	// cout<<win[0]<<" "<<win[1]<<endl;
	if (win[0]>0) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int board[3][3];
		int countX=0, countO=0;
		char c;
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				cin>>c;
				if (c=='X'){
					board[i][j]=1;
					countX++;
				}
				else{
					board[i][j]=0;
					countO++;
				}
			}
		} 
		if (countX!=5 && countO!=4){
			cout<<"Invalid"<<endl;
			continue;
		}
		if (winBoth(board)){
			cout<<"Invalid"<<endl;
			continue;
		}
		cout<<"Valid"<<endl;
	} 
	return 0;
}