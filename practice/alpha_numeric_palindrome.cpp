/*
You are given a string containing the alphanumeric character. Find whether the string is palindrome or not.
*/

#include <bits/stdc++.h>
using namespace std;

string new_s="";

void isValidChar(char c){
	int i = (int) c;
	if ((i>=97 && i<=122) || (i>=48 && i<=57)){
		new_s+= c;
	}
	else if (i>=65 && i<=90){
		new_s+=  (char) (i+32);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	cin.ignore();
	while (t--){
		string s;
		new_s="";
		getline(cin,s);
		for (int i=0;i<s.size();i++){
			isValidChar(s[i]);
		}
		s = new_s;
		reverse(new_s.begin(), new_s.end());
		if (s==new_s){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}