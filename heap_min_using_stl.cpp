#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue <int, vector<int> , greater<int> > heap;
	heap.push(3);
	heap.push(2);
	heap.push(6);
	heap.push(1);
	heap.push(12);
	heap.pop();
	while (!heap.empty()){
		cout<<heap.top();
		heap.pop();
		cout<<endl;
	}
	return 0;
}