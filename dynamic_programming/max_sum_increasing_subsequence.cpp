#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] = {4,6,1,3,8,4,6};
	int n=7;
	int dp[n];
	int index[n];
	for (int i=0;i<n;i++){
		dp[i] = arr[i];
		index[i] = i;
	}
	int max_finally = INT_MIN;
	for (int i=1;i<n;i++){
		for (int j=0;j<n;j++){
			if (arr[j]<arr[i]){
				if (dp[i]<arr[i]+dp[j]){
					dp[i]=arr[i]+dp[j];
					index[i] = j;
					max_finally = max(max_finally, dp[i]);
				}
			}
		}
	}
	cout<<max_finally<<endl;
	return 0;
}