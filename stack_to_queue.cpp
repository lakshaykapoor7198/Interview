#include <bits/stdc++.h>
using namespace std;

stack <int > s1;
stack <int > s2;

class Queue{
public:
	void push(int data){
		s1.push(data);
		cout<<data<<" pushed."<<endl;
	}

	int pop(){
		int x;
		if(s2.empty()){
			while (!s1.empty()){
				x= s1.top();
				s1.pop();
				s2.push(x);
			}
		}
		x = s2.top();
		s2.pop();
		return x;
	}
};	


int main(int argc, char const *argv[])
{
	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	cout<<q.pop()<<" popped."<<endl;
	q.push(4);
	cout<<q.pop()<<" popped."<<endl;
	return 0;
}