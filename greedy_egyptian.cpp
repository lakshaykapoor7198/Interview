#include <bits/stdc++.h>
using namespace std;
#define forLoop(i, n, s) for (int i=s;i<n;i++)

void egyptianFraction(int n, int d){

	if (n==0 || d==0){
		return;
	}
	if (n==1){
		cout<<" 1/"<<d;
		return;
	}
	if (d%n==0){
		cout<<" 1/"<<d/n;
		return;
	}
	if (n%d==0){
		cout<<n/d;
		return;
	}

	int c = ceil(float(d)/float(n));
	cout<<" 1/"<<c;
	cout<<" + ";
	egyptianFraction(n*c-d, d*c);
}

int main(int argc, char const *argv[])
{
	int n = 2;
	int d = 3;
	egyptianFraction(n,d);
	cout<<endl;
	return 0;
}