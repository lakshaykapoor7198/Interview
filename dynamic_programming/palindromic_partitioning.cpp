#include <bits/stdc++.h>
using namespace std;

bool palin(string s){
	for (int i=0;i<=s.length()/2;i++){
		if (s[i]!=s[s.length()-1-i]) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s = "abcbm";
	int n=5;
	int dp[n][n];
	for (int i=0;i<n;i++){
		dp[i][i]=0;
	}

	for (int len=2;len<=n;len++){
		for (int i=0;i<=n-len;i++){
			int j=i+len-1;
			if (palin(s.substr(i, len))){
				dp[i][j]=0;
			}
			else{
				dp[i][j] = INT_MAX;
				for (int k=i+1;k<=j;k++){
					dp[i][j] = min(dp[i][j], 1+dp[i][k-1]+dp[k][j]);
				}
			}
		}
	}
	cout<<dp[0][n-1]<<endl;			
	return 0;
}