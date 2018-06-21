#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[]= {-1,3,-4,2,-10};
	int n = 5,end, start,s;
	int max_here=0, max_so_far=0;
	for (int i=0;i<n;i++){
		max_here  =arr[i]+max_here;
		if (max_here<0) {
			max_here=0;
			s=i+1;
		}
		if (max_so_far<max_here) {
			end=i;
			start=s;
			max_so_far = max_here;
		}
	}
	cout<<max_so_far<<" "<<start<<" "<<end<<endl;
	return 0;
}