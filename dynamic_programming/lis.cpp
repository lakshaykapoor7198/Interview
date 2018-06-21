#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] = {3,4,-1,0,6,2,3};
	int n=7;
	vector <vector <int> >v(n);
	v[0].push_back(arr[0]);
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			if (arr[i]>arr[j] && v[i].size()<1+v[j].size()){
				v[i] = v[j];
			}
		}
		v[i].push_back(arr[i]);
	}
	vector <int> m;
	m = v[0];
	for (int i=1;i<n;i++){
		if (m.size()<v[i].size()) m=v[i];
	}

	for (int i=0;i<m.size();i++){
		cout<<m[i]<<" ";
	}
	cout<<endl;
	return 0;
}