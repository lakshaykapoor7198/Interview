#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {1,7,10,15,27,29};
	int n = 6;

	int dp[n][n];
	int i, k;
	int llap =2;
	for (i=0;i<n;i++) dp[i][n-1] = 2;
	for (int j=n-2;j>=1;j--){
		i=j-1;
		k=j+1;
		while (i>=0 && k<=n-1){
			if (arr[i]+arr[k]==2*arr[j]){
				dp[i][j] = 1+ dp[j][k];
				llap = max (llap, dp[i][j]);
				i--;
				k++;
			}
			else if (arr[i]+arr[k]>2*arr[j]){
				dp[i][j] = 2;
				i--;
			}
			else{
				k++;
			}
		}
		while (i>=0){
			dp[i][j]=2;
			i--;
		}
	}
	cout<<llap<<endl;
	return 0;
}