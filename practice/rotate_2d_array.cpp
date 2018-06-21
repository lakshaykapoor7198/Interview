#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int  t = *a;
	*a = *b;
	*b = t;
}

void solve(int arr[10][10], int start, int n){
	if (n==1){
		return;
	}
	int end = n-1;
	swap(&arr[start][start], &arr[start][end]);
	swap(&arr[start][start], &arr[end][start]);
	swap(&arr[end][start], &arr[end][end]);

	if (start==end-1){
		return;
	}
	for (int i=start+1;i<end;i++){
		swap(&arr[start][i], &arr[i][end]);
	}
	for (int i=start+1;i<end;i++){
		swap(&arr[start][i], &arr[i][start]);
	}
	for (int i=start+1;i<end;i++){
		swap(&arr[i][start], &arr[end][i]);
	}
	for (int i=start+1;i<=end/2;i++){
		swap(&arr[start][i], &arr[start][end-i]);
		swap(&arr[end][i], &arr[end][end-i]);
	}
	solve(arr, start+1, n-1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int arr[10][10];
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		solve(arr,0,n);
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}