#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s1="abcdef" , s2 = "azced";
	int n = s1.length(), m = s2.length();
	int dp[n+1][m+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			if (i==0) dp[i][j] = j;
			else if (j==0) dp[i][j] = i;
			else if (s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}