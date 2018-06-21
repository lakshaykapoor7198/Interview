#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int arr[n];
		for (int i=0;i<n;i++){
			cin>>arr[i];
		}
		int flag = 1;
		int start = 0;
		int end = n-1;
		while(1){
			if (start==end || start==end-1){
				flag=0;
				cout<<0<<endl;
				break;
			}
			if (arr[start+1]>=arr[start]){
				start++;
			}
			if (arr[end-1]>=arr[end]){
				end--;
			}
			if (arr[end-1]<arr[end] && arr[end-1]>arr[start]){
				end--;
			}
			else if (arr[start+1]<arr[start] && arr[start]>arr[end]){
				start++;
			}
			else {
				break;
			}
		}
		if (flag==0) continue;
		int max_water = 0;
		int sub = min(arr[start], arr[end]);
		for (int i=start+1;i<end;i++){
			if (sub>arr[i]) max_water+=sub-arr[i];
		}
		cout<<max_water<<endl;
	}
	return 0;
}