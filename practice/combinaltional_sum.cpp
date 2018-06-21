/*When any no of time a no can be taken */

#include <bits/stdc++.h>
using namespace std;

void solveUtil(int arr[], int i, int sum, vector <int> &v, int n, int &flag){
	if (i==n){
		return;
	}
	if (sum==0){
		cout<<"(";
		int j;
		for (j=0;j<v.size()-1;j++){
			cout<<v[j]<<" ";
		}

		cout<<v[j]<<")";
		flag=1;
		return;
	}
	if (sum<arr[i]){
		return;
	}
	v.push_back(arr[i]);
	solveUtil(arr, i, sum-arr[i], v, n, flag);
	v.pop_back();
	solveUtil(arr, i+1, sum, v,n, flag);
}

void solve(int arr[], int n, int sum ){
	vector <int> v;
	int flag=0;
	solveUtil(arr, 0, sum, v, n, flag);
	if (flag==0) cout<<"Empty";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n,sum;
		cin>>n;
		int arr[n];
		for (int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr, arr+n);
		int final_arr[n];
		int j=1;
		final_arr[0]=arr[0];
		for (int i=1;i<n;i++){
			if (arr[i]!=arr[i-1]){
				final_arr[j]=arr[i];
				j++;
			}
		}
		cin>>sum;
		solve(final_arr, j, sum);
	}
	return 0;
}