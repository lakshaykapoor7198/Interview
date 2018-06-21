#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int arr[n][n];
		int max_row_zero = INT_MIN;
		int max_col = 0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>arr[i][j];
				if (i==0){
					if (arr[i][j]>max_row_zero){
						max_row_zero=arr[i][j];
						max_col=j;
					}
				}
			}
		}
		if (n==1) return arr[0][0];
		int dp[n][n], res=INT_MIN;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==0){
					dp[i][j]=arr[i][j];
				}
				else{
					if (j==0){
						dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
					}
					else if (j==n-1){
						dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);	
					}
					else{
						dp[i][j] = arr[i][j] + max(dp[i-1][j], max(dp[i-1][j+1], dp[i-1][j-1]));
					}
					if (i==n-1 && res<dp[i][j]) res= dp[i][j];
				}
			}
		}	
		
		cout<<res<<endl;	
	}
	return 0;
}