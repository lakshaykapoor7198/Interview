#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int s[] = {1,2,4,6,5,7};
	int f[] = {3,5,6,7,8,9};
	int profit[] = {5,6,5,4,11,2};
	int n=6;
	int dp[n];
	for (int i=0;i<n;i++){
		dp[i] = profit[i];
	}
	int res= INT_MIN;
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			if (s[i]>=f[j]){
				dp[i]= max(dp[i], profit[i]+dp[j]);
			}
		}
		res = max(res, dp[i]);
	}
	cout<<res<<endl;
	return 0;
}