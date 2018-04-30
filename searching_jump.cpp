#include <bits/stdc++.h>
using namespace std;


int jump(int arr[], int n, int x){
	int i=0,m = int(sqrt(n));
	int l=0,r=0;
	for (i=0;i<n;){
		if (arr[i]==x){
			return i;
		}
		if (arr[i]>x){
			r=i;
			l=i-m;
			break;
		}
		i=i+m;
	}

	for (i=l;i<=r;i++){
		if (arr[i]==x){
			return i;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
	int n = sizeof(arr) /sizeof(arr[0]);
	cout<<jump(arr, n, 55)<<endl;
	return 0;
}