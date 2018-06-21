#include <bits/stdc++.h>
using namespace std;

int solve(vector <vector <int > > dp,vector <vector <int > > visit, int arr[], int start, int end){
	if (visit[start][end]!=0){
		return dp[start][end];
	}
	if (start==end){
		visit[start][end] = 1;
		dp[start][end] = arr[start];
		return dp[start][end] ;
	}
	if (start==end-1){
		visit[start][end] = 1;
		dp[start][end]= max(arr[start], arr[end]);
		return dp[start][end] ;
	}
	dp[start][end] = max(arr[start] + min(solve(dp,visit,arr,start+2,end),solve(dp,visit,arr,start+1, end-1)),arr[end]+  min(solve(dp,visit,arr,start,end-2),solve(dp,visit,arr,start+1, end-1))); 
	visit[start][end]=1;
	return dp[start][end];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int arr[n] ;
		for (int i=0;i<n;i++) cin>>arr[i];
		vector <vector <int> > dp(n,vector <int>(n,0));
		vector <vector <int> > visit(n,vector <int>(n,0));
		cout<<solve(dp,visit,arr, 0, n-1)<<endl;
	}
	return 0;
}