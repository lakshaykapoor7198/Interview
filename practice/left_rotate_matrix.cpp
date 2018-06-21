#include <bits/stdc++.h>
using namespace std;


void printMatrix(int *arr, int m, int n,int k){
	for (int i=0;i<m;i++){
		int j=k;
		do{
			cout<<*((arr+i*n)+j)<<" ";
			j= (j+1)%n;
		}while (j!=k);
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int t, m, n, k;
	cin>>t;
	while (t--){
		cin>>m>>n>>k;
		int arr[m][n];
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		k=k%n;
		printMatrix(&arr[0][0],m,n,k);

	}
	return 0;
}