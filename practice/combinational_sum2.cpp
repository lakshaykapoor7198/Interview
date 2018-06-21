/*When only numbers from array can be taken*/

#include <bits/stdc++.h>
using namespace std;

void solveUtil(int arr[], int i, int sum, vector <int> &v, int n, vector <vector <int> > &res){
	if (sum==0){
		res.push_back(v);
		return;
	}
	if (i==n){
		return;
	}
	if (sum<arr[i]){
		return;
	}
	v.push_back(arr[i]);
	solveUtil(arr, i+1, sum-arr[i], v, n, res);
	v.pop_back();
	solveUtil(arr, i+1, sum, v,n, res);
}

void solve(int arr[], int n, int sum ){
	vector <int> v;
	vector < vector <int> > res;
	solveUtil(arr, 0, sum, v, n, res);
	if (res.size()==0) cout<<"Empty";
	else{
		int j;
		set <vector <int> > s(res.begin(),res.end());
		set<vector<int> >:: iterator m;
	    int n;
	    for(m=s.begin();m!=s.end(); m++)
	    {
	    	const vector<int>& k = (*m);
	      	cout<<"(";
	        for ( n=0;n<k.size()-1; n++)
            	cout << k[n] << " ";
         	cout<<k[n]<<")";
	    }
	}
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
		cin>>sum;
		solve(arr, n, sum);
	}
	return 0;
}