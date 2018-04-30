#include <bits/stdc++.h>
using namespace std;

int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
int n = sizeof(arr)/sizeof(arr[0]);
vector <int> a1,a2;
int sum=INT_MAX;



bool solveUtilTWar(int arr[], int visited[], vector <int> v1, vector<int>v2, int n, int total){
	if (total==n){
		int sum1 = abs(accumulate(v1.begin(), v1.end(),0) - accumulate(v2.begin(), v2.end(),0));
		if (n%2==0 && v1.size()==v2.size() && v2.size()==n/2 || 
			n%2!=0 && ((v1.size()==(n-1)/2 && v2.size()==(n+1)/2) || 
				(v2.size()==(n-1)/2 && v1.size()==(n+1)/2) )
		 )

		{
			if (sum1==0){
				a1 = v1;
				a2 = v2;
				sum = sum1;
				return true;
			}
			else if (sum1<sum){
				a1 = v1;
				a2 = v2;
				sum = sum1;
			}
			cout<<sum<<" ";
		}


		
		return false;
	}
	for (int i=0;i<n;i++){
		if (visited[i]==0){
			visited[i] = 1;
			v1.push_back(arr[i]);
			if (solveUtilTWar(arr, visited, v1, v2, n, total+1)==true){
				return true;
			}
			else{
				v1.pop_back();
				v2.push_back(arr[i]);
				if (solveUtilTWar(arr, visited, v1, v2, n ,total+1)==true){
					return true;
				}
				else{
					v2.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
	return false;
}


void tWar(int arr[], int n){
	vector <int > v1,v2;
	int visited[n];
	for (int i=0;i<n;i++) visited[i] = 0;

	if (solveUtilTWar(arr, visited, v1, v2, n,0)==false){
		cout<<"No solution exist\n";
	}
}

int main(int argc, char const *argv[])
{
	
	tWar(arr, n);
	for (int i=0;i<a1.size();i++){
		cout<<a1[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<a2.size();i++){
		cout<<a2[i]<<" ";
	}
	cout<<endl;
	cout<<"Sum is : "<<sum<<endl;
	return 0;
}