#include <bits/stdc++.h>
using namespace std;
#define forLoop(i,s, n) for (int i=s;i<n;i++)

void solve(string s1 , string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	int lcs[l1+1][l2+1];
	forLoop(i,0,l1+1) lcs[i][0]=0;
	forLoop(i,0,l2+1) lcs[0][i]=0;

	forLoop(i, 1, l1+1){
		forLoop(j, 1, l2+1){
			if (s1[i-1]==s2[j-1]){
				lcs[i][j] = 1+ lcs[i-1][j-1];
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	cout<<lcs[l1][l2]<<endl;
	string sLCS;
	int counter1 = l1, counter2= l2;
	while (counter1>0 && counter2>0){
		if (s1[counter1-1]==s2[counter2-1]){
			sLCS+=s1[counter1-1];
			counter1--;
			counter2--;
		}
		else{
			if (lcs[counter1-1][counter2]>lcs[counter1][counter2-1]){
				counter1--;
			}
			else{
				counter2--;
			}
		}
	}
	reverse(sLCS.begin(), sLCS.end());
	cout<<sLCS<<endl;
}


void solveSpaceOptimized(string s1, string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	int lcs[2][l2+1];
	bool b;
	forLoop(i, 0, l1+1){
		b = i &1;
		forLoop(j,0,l2+1){
			if (i==0 || j==0){
				lcs[b][j]=0;
			}
			else if (s1[i-1]==s2[j-1]){
				lcs[b][j] = lcs[1-b][j-1]+1;
			}
			else{
				lcs[b][j] = max(lcs[1-b][j], lcs[b][j-1]);
			}
		}
	}
	cout<<lcs[b][l2]<<endl;
}

int main(int argc, char const *argv[])
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	// cout<<s1<<" "<<s2<<endl;
	// solve(s1,s2);
	solveSpaceOptimized(s1, s2);
	return 0;
}