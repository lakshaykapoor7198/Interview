#include <bits/stdc++.h>
using namespace std;


int search(int arr[], int l, int r, int x){
	if (l==r && arr[l]!=x){
		return -1;
	}
	int m = l + (((x-arr[l])*(r-l))/(arr[r]-arr[l]));
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

int main(int argc, char const *argv[])
{
	int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
	int n = sizeof(arr) /sizeof(arr[0]);
	cout<<search(arr,0, n-1, 55)<<endl;
	return 0;
}