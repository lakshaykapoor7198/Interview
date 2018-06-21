#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n=2, k=6;
	int dp[n+1][k+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=k;j++){
			if (j==0) dp[i][j]=0;
			else if (i==0) dp[i][j] = 0;
			else if (i==1) dp[i][j] = j;
			else if (j<i) dp[i][j] = dp[i-1][j];
			else {
				int min_of_worst = INT_MAX;
				for (int k=1;k<=j;k++){
					int res = max(dp[i][j-k], dp[i-1][k-1]);
					min_of_worst = min(res, min_of_worst);
				}
				dp[i][j] = 1+ min_of_worst;
			}
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=k;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][k]<<endl;
	return 0;
}