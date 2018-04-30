#include <bits/stdc++.h>
using namespace std;

void printList(list <int> l){
	list <int>::iterator it;
	for (it=l.begin(); it!=l.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	list <int> l;
	l.push_back(31);
	l.push_back(21);
	l.push_back(13);
	l.push_back(41);
	l.push_back(15);
	cout<<"Size is: "<<l.size()<<endl;
	printList(l);
	l.reverse();
	printList(l);
	l.sort();
	printList(l);
	return 0;
}