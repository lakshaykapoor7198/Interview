#include <bits/stdc++.h>
using namespace std;

bool found(string s){
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", "icecream","and", "go","i","love","ice","cream"};
	int dict_size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i=0;i<dict_size;i++){
		if (dictionary[i]==s){
			return true;
		}
	}
	return false;
}

void wordBreakUtil(string s, int n, string result){
	if (n==0){
		cout<<result<<endl;
		return;
	}

	for (int i=0;i<=n;i++){
		string str = s.substr(0,i);
		if (found(str)){
			wordBreakUtil(s.substr(i,n-i), n-i, result + str + " ");
		}
	}
	return;
}

void wordBreak(string s){
	wordBreakUtil(s,s.length(), "");
}


int main(int argc, char const *argv[])
{
	wordBreak("iloveicecreamandmango");
	wordBreak("ilovesamsungmobile");	
	return 0;
}