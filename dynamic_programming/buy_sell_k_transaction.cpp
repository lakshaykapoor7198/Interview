#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int m){
	int dp[n+1][m+1];
	for (int i=0;i<=n;i++){
		int maxDiff = -arr[0];
		for (int j=0;j<=m;j++){
			if (i==0 || j==0) dp[i][j]=0;
			else{
				dp[i][j] = max(dp[i][j-1], arr[j-1]+maxDiff);
				maxDiff = max(maxDiff, dp[i-1][j]-arr[j-1]);
			}
		}
	}
	cout<<dp[n][m]<<endl;	
}

int main(int argc, char const *argv[])
{
	int arr[] = {2,5,7,1,4,3,1,3};
	int days= 8;
	int k=3;
	solve(arr, k, days);
	return 0;
}