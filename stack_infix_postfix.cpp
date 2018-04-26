#include <bits/stdc++.h>
using namespace std;

bool isOp(char c){
	if (int(c)>=97 && int(c)<=122 || int(c)>=48 && int(c)<=57){
		return false;
	}
	return true;
}

int prec(char c){
	if (c=='^'){
		return 5;
	}
	if (c=='/' || c=='*'){
		return 4;
	}
	if (c=='+' || c=='-'){
		return 3;
	}
	if (c=='(' || c==')'){
		return 2;
	}
}

void itp(string s){
	stack <char> q;
	string o="";
	int i;
	char c;
	for (i=0;i<s.length();i++){
		c=s[i];
		if (isOp(c)==false){
			o+=c;
		}
		else{
			if (q.empty()){
				q.push(c);
			}
			else{
				char a = q.top();
				if (c=='('){
					q.push(c);
				}
				else if (c==')'){
					while(q.top()!='(' && !q.empty()){
						o+=q.top();
						q.pop();
					}
					q.pop();
				}
				else{
					if (prec(c)>=prec(a)){
						q.push(c);
					}
					else{
						while (prec(q.top())>prec(c) && !q.empty()){
							char b = q.top();
							q.pop();
							o+=b;
						}
						q.push(c);
					}
				}
			}
		}
	}
	while(!q.empty()){
		o+=q.top();
		q.pop();
	}
	cout<<o<<endl;
}


int main(int argc, char const *argv[])
{
	string s = "a+b*(c^d-e)^(f+g*h)-i";
	itp(s);
	return 0;
}