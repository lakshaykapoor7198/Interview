#include <bits/stdc++.h>
using namespace std;
#define forLoop(i, n) for (int i=0;i<n;i++)

void coin_change(int coins[], int V, int n){
	int i=n-1;
	while (V && i>-1){
		int q = V/coins[i];
		int mod = V%coins[i];
		if (mod==0){
			cout<<q<<" "<<coins[i]<<" notes"<<endl;
			break;
		}
		if (q==0){
			i--;	
		}
		else if (q>=1){
			cout<<q<<" "<<coins[i]<<" notes"<<endl;
			V = V-q*coins[i];
			i--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};	
	int V = 93;
	int n = sizeof(coins)/sizeof(coins[0]);
	coin_change(coins, V, n);
	return 0;
}