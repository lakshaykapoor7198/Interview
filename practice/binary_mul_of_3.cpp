#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--){
		string s;
		cin>>s;
		int sum=0;
		for (int i=0;i<s.length();i++){
			if (s[i]=='1'){
				if (i & 1){
					sum+=2;
				}
				else{
					sum+=1;
				}
			}
		}
		int res = (sum%3==0)?1:0;
		cout<<res<<endl;
	}
	return 0;
}