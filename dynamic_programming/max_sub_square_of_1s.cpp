#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n=4, m=5;
	int arr[n][m]= {{0,0,1,1,1},
					{1,0,1,1,1},
					{0,1,1,1,1},
					{1,0,1,1,1}};
	int max_size=INT_MIN;
	int dp[n][m];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (i==0 || j==0) dp[i][j] = arr[i][j];
			else if(arr[i][j]==0) dp[i][j]=0;
			else if (arr[i-1][j] && arr[i][j-1]&&arr[i-1][j-1]) dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
			else dp[i][j]=1;

			if (max_size<dp[i][j]) max_size =dp[i][j];
		} 
	}
	cout<<max_size<<endl;
	return 0;
}