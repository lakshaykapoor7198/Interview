#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int coins[] = {7,2,3,6};
	int n=4;
	int total=13;
	int dp[total+1],index[total+1];
	dp[0] = 0;
	for (int i=1;i<=total;i++){
		dp[i]=INT_MAX;
	}
	memset(index, -1, (total+1)*sizeof(index[0]));
	for (int i=0;i<n;i++){
		for (int j=1;j<=total;j++){
			if (j>=coins[i]){
				if (dp[j-coins[i]]!=INT_MAX){
					if (dp[j]>1+dp[j-coins[i]]){
						dp[j]=1+dp[j-coins[i]];
						index[j] = i;
					}
				}
			}
		}
	}
	for (int i=0;i<total+1;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<total+1;i++){
		cout<<index[i]<<" ";
	}
	cout<<endl;
	cout<<dp[total]<<endl;	
	return 0;
}