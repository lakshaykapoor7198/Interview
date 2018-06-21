#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector <int> v(n,0);
		for (int i=0;i<n;i++){
			cin>>v[i];
		}
		int size = v.size();
		int no_of_operations = 0;
		int start = 0;
		int end = size -1;
		while (size>1){	
			if (v[start]==v[end]) {
				size-=2;
				start++;
				end--;
			}
			else{
				if (v[start]<v[end]){
					v[start+1] = v[start]+v[start+1];
					start++;
				}
				else{
					v[end-1] = v[end-1]+v[end];
					end--;
				}
				no_of_operations++;
				size--;
			}
		}
		cout<<no_of_operations<<endl;
	}
	return 0;
}