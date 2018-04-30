#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void selectionSort(int arr[], int n){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (arr[i]>arr[j]){
				int temp  = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void bubbleSort(int arr[], int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			if (arr[j+1]<arr[j]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void insertionSort(int arr[], int n){
	int i,j;
	for (i=1;i<n;i++){
		j=i-1;
		int temp = arr[i];
		while (j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}


void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int k = l;
	int i,j;
	int L[n1], R[n2];
	for (i=0;i<n1;i++){
		L[i] = arr[l+i];
	}
	for (i=0;i<n2;i++){
		R[i] = arr[m+1+i];
	}
	i=0;j=0;
	while(i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	} 
	while (i<n1){
		arr[k] = L[i];
		i++;
		k++;
	} 
	while (j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if (l<r){
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr, l , m ,r);
	}
}


void partition(int arr[], int l , int r){
	int pivot = arr[r];

	

}

void quickSort(int arr, int l, int r){
	if (l<r){
		int pi = partition(arr, l, r);
		quickSort(arr, l,pi);
		quickSort(arr, pi+1, r);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // selectionSort(arr, n);
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    // mergeSort(arr, 0, n-1);
    quickSort(arr,0,n-1);
    printArray(arr,n);
	return 0;
}