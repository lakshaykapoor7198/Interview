#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n=3, m=4;
	int arr[n][m]= {{1,3,5,8},
					{4,2,1,7},
					{4,3,2,3}};
	
	int dp[n][m];
	dp[0][0] = arr[0][0];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (i==0 && j>=1) dp[i][j] = arr[i][j]+ dp[i][j-1];
			else if (j==0 && i>=1) dp[i][j] = arr[i][j]+ dp[i-1][j];
			else{
				dp[i][j] = arr[i][j]+ min(dp[i-1][j], dp[i][j-1]);
			}
		} 
	}
	cout<<dp[n-1][m-1]<<endl;
	return 0;
}