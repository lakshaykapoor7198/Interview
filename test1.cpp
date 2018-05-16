#include <bits/stdc++.h>	
using namespace std;

bool palindrome(string s){
	for (int i=0;i<s.length();i++){
		if(s[i]!=s[s.length()-i-1]){
			return false;
		}
	}
	return true;
}

bool possible(string s,int i, int k, map <char, int> m){
	multimap <char, int> ::iterator it;
	for (it=m.begin(); it!=m.end(); ++it){
		if (it->second==k || it->second<k){
			return true;
		}
		else if (possible(s, k-(it->second), k, m)){
			return true;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int t,k;
	cin>>t;
	int i;
	map <char, int> m;
	for (i=0;i<s.length();i++){
		if (m.find(s[i])!=m.end()){
			m[s[i]] = m[s[i]] +1;
		}
		else{
			m[s[i]]= 1;
		}
	}

	multimap <char, int> ::iterator it;
	for (it=m.begin(); it!=m.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}
	while (t--){
		cin>>k;
		if (k==1){
			cout<<k<<endl;
		}

		if (k>s.length()){
			cout<<-1<<endl;
		}
		if (possible(s,k,k, m)){
			cout<<k<<endl;
		}
		else{
			cout<<-1;
		}

	}
	return 0;
}