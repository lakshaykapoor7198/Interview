#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] = {2,3,1,1,2,4,2,0,1,1};
	int n=10;
	int dp[n];
	int index[n];
	index[0] = 0;
	memset(index, -1, n*sizeof(index[0]));
	dp[0]=0;
	for (int i=1;i<n;i++) dp[i] = INT_MAX;
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			if (arr[j]+j>=i){
				if (dp[i]>1+dp[j]){
					dp[i] = 1+dp[j];
					index[i] = j;
				}
			}
		}
	}
	cout<<dp[n-1]<<endl;
	for (int i=0;i<n;i++) cout<<index[i]<<" ";
	cout<<endl;
	return 0;
}