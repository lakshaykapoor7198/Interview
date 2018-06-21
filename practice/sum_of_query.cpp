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
		int prev_sum=0,temp;
		for (int i=0;i<n;i++){
			cin>>temp;
			arr[i] =temp+prev_sum;
			prev_sum = arr[i];
		}
		int q,start,end;
		cin>>q;
		for (int i=0;i<q;i++){
			cin>>start>>end;
			start--;
			end--;
			if (start!=0){
				cout<<arr[end]-arr[start-1]<<" ";
			}
			else cout<<arr[end]<<" ";
		}
		cout<<endl;
	}
	return 0;
}