#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string text = "xaabyc",  pattern="xa*b.c";
	int n = 6, m=6;
	int dp[n+1][m+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			if (i==0 && j==0 ) dp[i][j]=1;
			else if (i==0 && pattern[0]=='.'||pattern[1]=='*'){
				dp[i][j]=1;
			}
			else if (i==0 && !(pattern[0]=='.'||pattern[1]=='*')){
				dp[i][j]=0;
			}
			else if (j==0) dp[i][j]=0;
			else{
				if (text[i-1]==pattern[j-1] || pattern[j-1]=='.'){
					dp[i][j]=dp[i-1][j-1];
				}
				else if (pattern[j-1]=='*'){
					if (dp[i][j-2]==1) dp[i][j]=1;
					else if(pattern[j-2]==text[i-1]){
						dp[i][j] = dp[i-1][j];
					}
					else{
						dp[i][j]=0;
					}
				}
				else{
					dp[i][j]=0;
				}
			}
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][m]<<endl;		
	return 0;
}