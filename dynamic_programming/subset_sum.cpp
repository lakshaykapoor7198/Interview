#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] =  {2,3,7,8,10};
	int n=5;
	int sum=11;
	bool dp[n][sum+1];
	bool pos = false;
	for (int i=0;i<n;i++){
		for (int j=0;j<=sum;j++){
			if (j==0) dp[i][j] = true;
			else if (arr[i]>j) {
				if (i==0) dp[i][j] = false;
				else dp[i][j] = dp[i-1][j];
			}
			else{
				if (i==0 && arr[i]==j) dp[i][j] = true;
				else if (i!=0){
					dp[i][j] = dp[i-1][j-arr[i]];
					if (!dp[i][j]) dp[i][j] = dp[i-1][j];	
				}
				else{
					dp[i][j] = false;
				}

				if (j==sum && dp[i][j]) pos=true;
			}
		}
	}
	cout<<pos<<endl;
	return 0;
}