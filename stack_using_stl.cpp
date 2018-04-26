#include <bits/stdc++.h>
using namespace std;

void show(stack <int> s){
	stack <int> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
	show(s);
	return 0;
}