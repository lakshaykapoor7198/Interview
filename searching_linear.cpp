#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x){
	for (int i=0;i<n;i++){
		if (arr[i]==x){
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) /sizeof(arr[0]);
	cout<<search(arr,n, 6)<<endl;
	return 0;
}