#include <map>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	map <int, int>  m;
	pair <int , int> p1;
	p1.first = 1;
	p1.second =2;
	m.insert(p1);

	m.insert(pair <int, int> (5,6));
	if (m.find(5)!=m.end()){
		cout<<"Found\n";
	}

	map <int, int> :: iterator it;
	for (it =m.begin(); it!=m.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;
}