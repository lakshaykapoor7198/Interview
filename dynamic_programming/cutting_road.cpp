/*Just like knapsack */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int total_len=5;
	int lengths[] = {1,2,3,4};
	int values[] = {2,5,7,8};
	int n=4;
	int dp[n][total_len+1];
	for (int i=0;i<n;i++){
		for (int j=0;j<=total_len;j++){
			if (j==0 || i==0 && j%lengths[i]!=0) dp[i][j]=0;
			else if (i==0 && j%lengths[i]==0) dp[i][j]=(j/lengths[i])*values[i]; 
			else if (lengths[i]>j) dp[i][j] = dp[i-1][j];
			else {
				dp[i][j] = max(dp[i-1][j], values[i]+dp[i][j-lengths[i]]);
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<=total_len;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;	
	}
	cout<<dp[n-1][total_len]<<endl;
	return 0;
}