#include <bits/stdc++.h>
using namespace std;
#define forLoop(i, n, s) for (int i=s;i<n;i++)

struct job{
	char a;
	int d;
	int p;
};

bool anotherComp(job a, job b){
	return a.p >b.p;
}

void solve(job arr[], int n){
	sort(arr, arr+n, anotherComp);
	int min = 1;
	cout<<arr[0].a<<" ";
	forLoop(i, n, 1){
		if (arr[i].d>min){
			cout<<arr[i].a<<" ";
			min++;
		}
	}
	cout<<endl;

}

int main(int argc, char const *argv[])
{
	job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
	solve(arr, 5);
	return 0;
}