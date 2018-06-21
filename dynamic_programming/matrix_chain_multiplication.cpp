/*Memorize */

#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int mat[] =  {40, 20, 30, 10, 30};
	int n=5;
	int dp[n][n];
	for (int i=1;i<n;i++){
		dp[i][i] = 0;
	}

	for (int l=2;l<n;l++){
		for (int i=1;i<=n-l;i++){
			int j = i+l-1;
			dp[i][j] = INT_MAX;
			for (int k=i;k<j;k++){
				int q = dp[i][k] + dp[k+1][j] + mat[i-1] * mat[k] *mat[j];
				dp[i][j] = min(q, dp[i][j]);
			}
		}
	}	
	cout<<dp[1][n-1]<<endl;
	return 0;
}