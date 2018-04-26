#include <bits/stdc++.h>
using namespace std;

void show(queue <int> q){
	queue <int> q1 = q;
	while (!q1.empty()){
		cout<<q1.front()<<" ";
		q1.pop();
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	queue <int > q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.front()<<" popped.\n";
	q.pop();
	show(q);
	return 0;
}