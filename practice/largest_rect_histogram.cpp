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
		for (int i=0;i<n;i++) cin>>arr[i];
		int res = INT_MIN,j,k,x,y;
		
		for (int i=0;i<n;i++){
			j=i-1,k=i+1;
			if (i!=0){
				while (j>=0){
					if (arr[j]<arr[i]){
						break;
					}
					j--;
				}
			}
			else {
				j=-1;
			}

			if (i!=n-1){
				while (k<n){
					if (arr[k]<arr[i]){
						break;
					}
					k++;
				}
			}
			else{
				k=n;
			}
			res  =max(res, arr[i]*(k-j-1));
		}
		cout<<res<<endl;
	}
	return 0;
}
