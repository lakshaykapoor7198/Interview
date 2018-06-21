#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int l, int m, int h){
	int n1 = m-l+1;
	int n2 = h-m;
	int le[n1], r[n2];
	for (int i=l;i<=m;i++){
		le[i-l] = arr[i];
	}
	for (int i=m+1;i<=h;i++){
		r[i-m-1] = arr[i];
	}

	int j=0,k=0, z=l;
	while (j<n1 && k<n2){
		if (le[j]<r[k]){
			arr[z] = le[j];
			z++;
			j++;
		}
		else{
			arr[z] = r[k];
			k++;
			z++;
		}
	}

	while (j<n1){
		arr[z] = le[j];
		z++;
		j++;
	}

	while (k<n2){
		arr[z] = r[k];
		z++;
		k++;
	}
}

void merge(int arr[], int l, int h){
	if (l<h){
		int m = l + (h-l)/2;
		merge(arr, l, m);
		merge(arr, m+1, h);
		mergeSort(arr, l, m, h);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {3,2,4,1,6,5};
	int n=6;
	merge(arr,0, n-1);
	for (int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}