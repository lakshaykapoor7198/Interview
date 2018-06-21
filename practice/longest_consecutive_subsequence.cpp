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
		sort(arr, arr+n);
		int max_len = 1, max_for_this=1;
		for (int i=1;i<n;i++){
			if (arr[i]==arr[i-1]+1){
				max_for_this++;
				if (i==n-1 && max_len<max_for_this){
					max_len = max_for_this;
				}
			}
			else{
				if (max_len<max_for_this)	max_len = max_for_this;
				max_for_this=1;
			}
		}
		cout<<max_len<<endl;
	}
	return 0;
}	