/*
Given an integer X within the range of 0 to 9, and given two positive integers as upper and lower bounds respectively, find the number of times X occurs as a digit in an integer within the range, excluding the bounds. Print the frequency of occurrence as output.
*/

#include <bits/stdc++.h>
using namespace std;

int countDigit(int n, int x){
	int count=0;
	while (n){
		if (n%10==x) count++;
		n=n/10;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int t,x,l,u;
	cin>>t;
	while (t--){
		cin>>x>>l>>u;
		int count = 0;
		for (int i=l+1;i<u;i++){
			count+=countDigit(i, x);
		}
		cout<<count<<endl;
	}
	return 0;
}