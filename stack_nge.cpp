#include <bits/stdc++.h>
using namespace std;

void nge(int arr[], int n){
	stack <int> s;
	s.push(arr[0]);
	for (int i=1;i<n;i++){
		if (s.top()<arr[i]){
			while (!s.empty() && s.top()<arr[i]){
				cout<<s.top()<<" "<<arr[i]<<endl;
				s.pop();
			}
			s.push(arr[i]);
		}
		else{
			if (arr[i]>s.top()){
				int x = s.top();
				s.pop();
				s.push(arr[i]);
				s.push(x);
			}
			else{
				s.push(arr[i]);
			}
		}
	}
	while (!s.empty()){
		cout<<s.top()<<" "<<-1<<endl;
		s.pop();
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {4,5,2,3};
	int n=4;
	nge(arr,n);
	return 0;
}