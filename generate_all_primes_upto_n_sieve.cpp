#include <bits/stdc++.h>
using namespace std;

void sieve(int n){
	vector <bool> v(n+1, true);
	v[0] = false, v[1] = false;
	for (int i=2;i*i<=n;i++){
		if (v[i]==true){
			for (int j=2*i;j<=n;j+=i){
				v[j]=false;
			}
		}
	}
	for (int i=2;i<=n;i++){
		if (v[i]) cout<<i<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n=13;
	sieve(n);
	return 0;
}