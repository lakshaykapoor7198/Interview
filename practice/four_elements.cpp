/*
Given an array of integers, find a combination of four elements in the array whose sum is equal to a given value X.
*/


/*
Below sol incorrect:
Refer : https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for (int i=0;i<n;i++) cin>>arr[i];
	    sort(arr, arr+n);
	    int f=1;
	    for (int i=0;i<n-3;i++){
	        for (int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                while (l<r){
                    if (arr[i]+arr[j]+arr[l]+arr[r]==k){
                        f=0;
                        cout<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" "<<arr[r]<<" $";
                    }
                    else if (arr[i]+arr[j]+arr[l]+arr[r]<k){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
    	    }   
	    }
	    if (f==1) cout<<-1;
	    cout<<endl;
	}
	return 0;
}