#include <bits/stdc++.h>
using namespace std;

struct Box{
	int l,w,h;
};

bool comp(Box a, Box b){
	return (a.l*a.w > b.l*b.w);
}

void solve(Box arr[], int n){
	Box generated[3*n];
	int j=0;
	for (int i=0;i<n;i++){
		Box b = arr[i];
		int temp[] = {b.l, b.w, b.h};
		sort(temp , temp+3);
		generated[j++] = {temp[2], temp[1], temp[0]};
		generated[j++] = {temp[2], temp[0],temp[1]};
		generated[j++] = {temp[1], temp[0], temp[2]};
	}
	sort(generated, generated+3*n, comp);

	int max_heights[3*n];
	int index[3*n];
	for (int i=0;i<3*n;i++){
		max_heights[i] = generated[i].h;
		index[i] = i;
	}

	for (int i=1;i<3*n;i++){
		for (int j=0;j<i;j++){
			if (generated[j].l > generated[i].l && generated[j].w>generated[i].w){
				if (max_heights[i]<max_heights[j]+generated[i].h){
					max_heights[i]=max_heights[j]+generated[i].h;
					index[i]= j;
				}
			}
		}
	}
	int max_obtained = max_heights[0];
	int k = 0;
	for (int i=1;i<3*n;i++){
		if (max_heights[i]>max_obtained){
			max_obtained=max_heights[i];
			k = i;
		}
	}
	cout<<max_obtained<<endl;
	while (1){
		cout<<generated[k].l<<" "<<generated[k].w<<" "<<generated[k].h<<endl;
		if (index[k]==k){
			break;
		}
		k = index[k];
	}
}

int main(int argc, char const *argv[])
{
	Box arr[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
	int n=4;
	solve(arr, n); 
	return 0;
}