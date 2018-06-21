#include <bits/stdc++.h>
using namespace std;

int* lps(string s){
	int n = s.length();
	int j=0, i=1;
	int *temp = new int[n];
	temp[0] = 0;
	while(i<n && j<n){
		if (s[i]==s[j]){
			temp[i]=j+1;
			i++;
			j++;
		}
		else {
			if (j==0) {
				temp[i] = 0;
				i++;
			}
			else{
				j = temp[j-1];
			}
		}
	}
	return temp;
}

int main(int argc, char const *argv[])
{
	// string s = "acacabacacabacacac";
	// int *temp = lps(s);
	// int n = s.length();
	// cout<<temp[n-1]<<endl;
	string s = "ababcabcabababd";
	string pat = "ababd";
	int n = s.length();
	int *temp = lps(pat);
	int i=0,j=0;
	while(i<n){
		if (s[i]==pat[j]){
			i++;
			j++;
			if (j==pat.length()){
				cout<<i-j<<endl;
				return 0;
			}
		}
		else {
			if (j!=0)	j=temp[j-1];
			else i++;
		}
	}
	cout<<-1<<endl;
	return 0;
}