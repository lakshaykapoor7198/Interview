#include <bits/stdc++.h>
using namespace std;
#define forLoop(i, n, s) for (int i=s;i<n;i++)

struct activities{
	int s,f;
};


int comp(const void *a, const void *b){
	activities *a1 = (activities *) a;
	activities *b1 = (activities *) b;
	return (a1->f>b1->f);
}

bool anotherComp(activities a, activities b){
	return a.f <b.f;
}

void solve(int s[], int f[], int n){
	activities arr[n];
	forLoop(i, n, 0){
		arr[i].s= s[i];
		arr[i].f = f[i];
	}
	// qsort(arr, n, sizeof(arr[0]), comp);
	sort(arr, arr+n, anotherComp);
	int min = arr[0].f;
	cout<<0<<" ";
	forLoop(i, n, 1){
		if (arr[i].s > min){
			cout<<i<<" ";
			min  = arr[i].f;
		}
	}
	cout<<endl;

}

int main(int argc, char const *argv[])
{
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);
	solve(s, f, n);
	return 0;
}