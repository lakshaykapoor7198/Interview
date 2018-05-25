#include <bits/stdc++.h>
using namespace std;
#define forLoop(i, n) for (int i=0;i<n;i++)

struct item{
	int val;
	int weight;
};

bool myComp(item a, item b){
	return ((float(a.val)/a.weight)>(float(b.val)/b.weight));
}

void knapsack(item arr[], int n, int W){
	sort(arr, arr+n, myComp);
	int w=0, v=0;
	for (int i=0;i<n;i++){
		if (arr[i].weight+w<=W){
			w+=arr[i].weight;
			v+=arr[i].val;
		}
		else{
			int left  =W-w;
			v+= arr[i].val *(float(left)/float(arr[i].weight));
			break;
		}
	}
	cout<<v<<endl;
}

int main(int argc, char const *argv[])
{
	int W = 50;
	item arr[] = {{60, 10}, {100, 20}, {120, 30}};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	knapsack(arr, n, W);
	return 0;
}