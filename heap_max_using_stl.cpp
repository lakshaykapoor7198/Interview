#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	vector <int> v;
	make_heap(v.begin(), v.end());
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	push_heap(v.begin(),v.end());


	vector <int> :: iterator it;
	for (it=v.begin(); it!=v.end(); ++it){
		cout<<*it<<" ";
	}	
	cout<<endl;
	pop_heap(v.begin(), v.end());
	for (it=v.begin(); it!=v.end(); ++it){
		cout<<*it<<" ";
	}	
	cout<<endl;
	v.pop_back();
	pop_heap(v.begin(), v.end());
	for (it=v.begin(); it!=v.end(); ++it){
		cout<<*it<<" ";
	}	
	cout<<endl;
	return 0;
}