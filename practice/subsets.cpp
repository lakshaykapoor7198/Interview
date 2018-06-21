#include <bits/stdc++.h>
using namespace std;

void getSubsets(int arr[], int n, vector <vector <int> > &v){
	int power_set_size = pow(2,n);
	for (int i=0;i<power_set_size;i++){
		vector <int > a;
		for (int j=0;j<n;j++){
			if (i & 1<<j){
				a.push_back(arr[j]);
			}
		}
		sort(a.begin(), a.end());
		v.push_back(a);
	}
}

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
		vector <vector <int> > v;
		getSubsets(arr,n, v);
		sort(v.begin(), v.end());
		set <vector<int> > m(v.begin(), v.end());
		set <vector<int> > :: iterator it;
		int i;
		for (it=m.begin();it!=m.end();++it){
			vector <int> a = (*it);
			cout<<"(";
			for (i=0;i<a.size();i++) {
				if (i!=a.size()-1) cout<<a[i]<<" ";
				else cout<<a[i]; 
			}
			cout<<")";
		}
		cout<<endl;
	}
	return 0;
}