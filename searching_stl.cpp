//Check exponential search
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<binary_search(arr, arr+n, 3)<<endl;
	cout<<lower_bound(arr, arr+n, 3)-arr<<endl;
	cout<<upper_bound(arr, arr+n, 3)-arr<<endl;
	return 0;
}