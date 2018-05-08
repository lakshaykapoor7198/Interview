#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}	

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	* b= temp;
}

void heapify(int arr[], int i, int n){
	int  l =2*i+1;
	int r = 2*i+2;
	int largest = i;
	if (l<n && arr[l]>arr[i]){
		largest = l;
	}
	if (r<n && arr[r]>arr[largest]){
		largest = r;
	}
	if (largest!=i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, largest, n);
	}
}

void heapSort(int arr[], int n){
	heapify(arr, 0, n);
	// printArray(arr, n);

	for (int i=n-1;i>=0;i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
	}
	printArray(arr, n);
}

int main(int argc, char const *argv[])
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr, n);
	// printArray(arr, n);
	return 0;
}