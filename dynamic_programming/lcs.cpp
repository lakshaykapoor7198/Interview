#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1="abcdaf";
	string s2 = "acbcf";
	int dp[1+s1.length()][1+s2.length()];
	for (int i=0;i<=s1.length();i++){
		for (int j=0;j<=s2.length();j++){
			if (i==0 || j==0) dp[i][j]=0;
			else if (s1[i-1]==s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<dp[s1.length()][s2.length()]<<endl;
	return 0;
}