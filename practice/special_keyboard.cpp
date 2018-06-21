#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int dp[76];
	memset(dp, 0, 76*sizeof(dp[0]));
	for (int i=1;i<=6;i++){
		dp[i] =i;
	}
	for (int i=7;i<=n;i++){
		int some=1;
		for (int j=i-3; j>=1;j--){
			some++;
			int max_now = (some)*dp[j];
			if (dp[i]<max_now) dp[i]=max_now;
		}
	}
	cout<<dp[n]<<endl;
}

int main(int argc, char const *argv[])
{
	int n=8;
	solve(n);
	return 0;
}