#include <bits/stdc++.h>
using namespace std;

void subsets(int arr[], int size){
	int power_set_size = pow(2, size);
	for (int i=0;i<power_set_size;i++){

		for (int j=0;j<size;j++){
			if (i & 1<<j){
				cout<<arr[j];
			}
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4};
	subsets(arr, 4);
	return 0;
}