#include <bits/stdc++.h>
using namespace std;
#define forLoop(i,s, n) for (int i=s;i<n;i++)

int getMax(int arr[], int n){
	int max =INT_MIN;
	int index= -1;
	forLoop(i, 0, n){
		if (arr[i]>max){
			max = arr[i];
			index=i;
		}
	}
	return index;
}

void lis(int arr[], int n){
	int temp[n];
	forLoop(i,0,n) temp[i]=1;
	forLoop(i, 1, n){
		forLoop(j, 0,i){
			if (arr[j]<arr[i] && temp[i]<1+temp[j]){
				temp[i]=1+temp[j];
			}
		}
	}
	int res = getMax(temp, n);
	// cout<<temp[res]<<endl;

	int counter = res;
	while (1){
		cout<<arr[counter]<<" ";
		if (temp[counter]==1){
			break;
		}
		forLoop(i, 0, counter){
			if (arr[i]<arr[counter] && temp[counter]==1+temp[i]){
				counter = i;
				break;
			}
		}
	}	
	cout<<endl;
}

void constructLIS(int arr[], int n){
	vector < vector <int> > v(n);
	v[0].push_back(arr[0]);
	forLoop(i, 1, n){
		forLoop(j, 0, i){
			if (arr[i]>arr[j] && v[i].size()<1+v[j].size()){
				v[i] = v[j];
			}
		}
		v[i].push_back(arr[i]);
	}
	vector <int> maxVector  = v[0];
	forLoop(i,1, v.size()){
		if (v[i].size()>maxVector.size()){
			maxVector = v[i];
		}
	}
	forLoop(i, 0, maxVector.size()){
		cout<<maxVector[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {3,4,-1,0,6,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	// lis(arr, n);
	constructLIS(arr, n);
	return 0;
}