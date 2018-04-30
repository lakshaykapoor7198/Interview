#include <bits/stdc++.h>
using namespace std;


int search(int arr[],int l, int r, int x){
	if (l==r && arr[l]!=x){
		return -1;
	}
	int m = (l+r)/2;
	if (arr[m]==x){
		return m;
	}
	else if (x<arr[m]){
		return search(arr, l, m-1, x);
	}	
	else{
		return search(arr, m+1, r, x);
	}
}

int iterative(int arr[], int n, int x){
	int l=0,r= n-1;

	while (l<r){
		int m = (l+r)/2;
		if(arr[m]==x){
			return m;
		}
		else if (x<arr[m]){
			r = m-1;
		}
		else{
			l = m+1;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) /sizeof(arr[0]);
	// cout<<search(arr,0, n-1, 6)<<endl;
	cout<<iterative(arr, n, 6)<<endl;
	return 0;
}