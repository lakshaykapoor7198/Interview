#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int h){
	int pivot = arr[h];
	int i=l,j=l;
	for (j=l;j<h;j++){
		if (arr[j]<=pivot){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[h]);
	return i;
}

void quick(int arr[], int l, int h){
	if (l<h){
		int pi = partition(arr, l, h);
		quick(arr, l, pi-1);
		quick(arr, pi+1, h);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {10,80,30,90,40,50,70};
	int n=7;
	quick(arr,0, n-1);
	for (int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}