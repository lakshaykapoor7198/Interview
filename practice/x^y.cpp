#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	int x,y;
	for (int i=2;i*i<=n;i++){
		int j=2;
		int res=i;
		while (res<n){
			res=pow(i,j);
			j++;
		}
		if (res==n){
			cout<<i<<" "<<j-1<<endl;
			break;
		}
	}
}

void solveAlter(int n){
	int x,y;
	for (int i=2;i*i<=n;i++){
		int j=1;
		int res=i;
		while (res<n){
			res=res*i;
			j++;
		}
		if (res==n){
			cout<<i<<" "<<j<<endl;
			return;
		}
	}
	cout<<"Not possible"<<endl;
}

int main(int argc, char const *argv[])
{
	int n =48;
	solveAlter(n);
	return 0;
}