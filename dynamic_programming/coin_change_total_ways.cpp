#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3};
	int n=3;
	int sum=5;
	int dp[n][sum+1];
	for (int i=0;i<n;i++){
		for (int j=0;j<=sum;j++){
			if (j==0 || i==0 && j%arr[i]==0) dp[i][j] = 1;
			else if (i==0 && j%arr[i]!=0) dp[i][j]=0;
			else{
				if (j<arr[i]){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] = dp[i][j-arr[i]] + dp[i-1][j];
				}
			}
		}
	}
	cout<<dp[n-1][sum]<<endl;
	return 0;
}