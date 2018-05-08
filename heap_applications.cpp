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


void kLargest(int arr[], int k, int n){
	for (int i=n/2-1;i>=0;i--){
		heapify(arr, i, n);
	}
	printArray(arr, n);
	for (int i=n-1; i>n-1-k;i--){
		swap(&arr[0], &arr[i]);
		cout<<arr[i]<<" ";
		heapify(arr, 0, i);
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {3,2,1,4,5};
	// kLargest(arr, 3, 5);
	return 0;
}