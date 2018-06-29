#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1 = "aab", s2= "axy", s3 = "aaxaby";
	int n=3, m=3;
	int dp[n+1][m+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (i==0 && j==0) dp[i][j]=0;
			else if (i==0){
				if (s2[j-1]==s3[j-1]) dp[i][j] = 1;
				else dp[i][j] = 0; 
			}
			else if (j==0){
				if (s1[i-1]==s3[i-1]) dp[i][j]=1;
				else dp[i][j]=0;
			}
			else{
				if (s2[j-1]==s3[i+j-1]){
					dp[i][j] = dp[i][j-1];
				}
				else if (s1[i-1]==s3[i+j-1]){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j]=0;
				}
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}