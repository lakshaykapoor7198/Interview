#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s1 ="abcdaf", s2 = "zbcdf";
	int n = s1.length(), m = s2.length();
	int dp[n+1][m+1];
	int max_length = INT_MIN;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			if (i==0 || j==0) dp[i][j]=0;
			else if (s1[i-1]==s2[j-1]) dp[i][j] =1+dp[i-1][j-1];
			else dp[i][j]=0;
			max_length = max(max_length, dp[i][j]);
		}
	}
	cout<<max_length<<endl;
	return 0;
}