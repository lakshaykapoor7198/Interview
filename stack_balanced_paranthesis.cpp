#include <bits/stdc++.h>
using namespace std;


bool check(string s){
	stack <char> q;
	for  (int i=0;i<s.length();i++){
		char c = s[i];
		if (c=='[' || c=='{' || c=='('){
			q.push(c);
		}
		else{
			if (c==']' && q.top()=='['){
				q.pop();
			}
			else if (c=='}' && q.top()=='{'){
				q.pop();
			}
			else if (c==')' && q.top()=='('){
				q.pop();
			}
			else{
				return false;
			}
		}
	}
	if (q.empty()){
		return true;
	}
	else{

		return false;
	}
}

int main(int argc, char const *argv[])
{
	string s = "[(])";
	cout<<check(s);
	return 0;
}