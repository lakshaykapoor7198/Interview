#include <bits/stdc++.h>
using namespace std;

int search1(int in[],int x,int start,int end){
	for (int i=start;i<=end;i++){
		if (in[i]==x){
			return i;
		}
	}
	return -1;
}

int *extract(int in[], int lo[], int start, int end, int n){
	int size = end - start +1;
	int *arr = (int *) malloc(size*sizeof(int));
	int k=0;
	for (int i=0;i<n;i++){
		if (search1(in, lo[i], start, end)!=-1)
			arr[k++] = lo[i];
	}
	return arr;
}

int main(int argc, char const *argv[])
{
	int in[] = {4,5,2,1,3};
	int lo[] = {1,2,3,4,5};
	int *arr  =extract(in, lo, 0, 2, 5);
	for (int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}