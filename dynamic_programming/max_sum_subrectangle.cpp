#include <bits/stdc++.h>
using namespace std;

int * kadanes(int temp[], int n){
	int *arr = new int[3];

	int some=INT_MIN, flag=0, index;
	for (int i=0;i<n;i++){
		if (temp[i]>0) {
			flag=1;
			break;
		}
		else{
			if (some<temp[i]){
				some=temp[i];
				index=i;
			}
		}
	}

	if (flag==0){
		*(arr + 0) = some;
		*(arr+1) = index;
		*(arr+2) = index;
		return arr; 
	}
	int max_here=0,max_so_far=0, s, start, end;
	for (int i=0;i<n;i++){
		max_here =temp[i]+max_here;
		if (max_here<0){
			max_here=0;
			s=i+1;
		}
		if (max_so_far<max_here){
			end=i;
			start= s;
			max_so_far =max_here;
		}
	}
	*(arr + 0) = max_so_far;
	*(arr+1) = start;
	*(arr+2) = end;
	return arr;
	
}

int main(int argc, char const *argv[])
{	int n=4, m=5;
	int arr[n][m] = {{2,1,-3,-4,5},
					{0,6,3,4,1},
					{2,-2,-1,4,-5},
					{-3,3,1,0,3}};

	int temp[n];
	int l,r,curr_sum=0,max_sum=0, maxLeft, maxRight, maxUp, maxDown;
	int *kad =new int[3];
	for (l=0;l<n;l++){
		for (r=l;r<n;r++){
			if (l==r){
				for (int i=0;i<n;i++){
					temp[i] = arr[i][l];
				}
			}
			else{
				for (int i=0;i<n;i++){
					temp[i] += arr[i][r];
				}
			}
			kad = kadanes(temp, n);
			curr_sum = *(kad+0);
			if (curr_sum>max_sum){
				max_sum = curr_sum;
				maxLeft = l;
				maxRight = r;
				maxUp = *(kad+1);
				maxDown = *(kad+2);
			}
		} 
	}
	cout<<max_sum<<" "<<maxLeft<<" "<<maxRight<<" "<<maxUp<<" "<<maxDown<<endl;
	return 0;
}