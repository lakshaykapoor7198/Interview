#include <bits/stdc++.h>
using namespace std;

void show(stack <int> s){
	stack <int> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<"\n";
}

void stock(int arr[], int n){
	stack <int> s;
	s.push(0);
	int S[n];
	for (int i=1;i<n;i++){
		if (arr[s.top()]<arr[i]){
			while (!s.empty() && arr[s.top()]<arr[i]){
				// cout<<arr[s.top()]<<" "<<arr[i]<<endl;
				S[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		else{
			if (arr[i]>arr[s.top()]){
				int x = s.top();
				s.pop();
				s.push(i);
				s.push(x);
			}
			else{
				s.push(i);
			}
		}
	}
	while (!s.empty()){
		S[s.top()] = n-s.top();
		s.pop();
	}
	reverse(S, S+n);
	for (int j=0; j<n; j++){
		cout<<S[j]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 4, 5, 90, 120, 80};
	
	int n=6;
	reverse(arr, arr+n);
	stock(arr,n);
	return 0;
}