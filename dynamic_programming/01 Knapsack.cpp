#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int weights[] = {1,3,4,5};
	int values[] = {1,4,5,7};
	int W = 7;
	int n = sizeof(weights)/sizeof(weights[0]);
	int dp[n+1][W+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=W;j++){
			if (i==0 || j==0) dp[i][j] =0;
			else if (weights[i-1]>j) dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = max(dp[i-1][j] , values[i-1] + dp[i-1][j-weights[i-1]]);
			}
		}
	}
	cout<<dp[n][W]<<endl;
	return 0;
}