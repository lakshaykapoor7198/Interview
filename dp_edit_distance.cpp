#include <bits/stdc++.h>
using namespace std;
#define forLoop(i,s, n) for (int i=s;i<n;i++)

int naive(string s1, string s2, int m , int n){
	if (m==0) return n;
	if (n==0) return m;
	if (s1[m-1]==s2[n-1]){
		return naive(s1,s2,m-1,n-1);
	}
	return 1 + min(naive(s1,s2,m, n-1), min(naive(s1,s2, m-1, n), naive(s1,s2,m-1,n-1)));
}

int main(int argc, char const *argv[])
{
	string str1 = "sunday";
    string str2 = "saturday";
    cout<<naive(str1, str2, str1.length(), str2.length());	
	    s a t u r d a y      
      0 0 0 0 0 0 0 0 0
    s 0  
    u 0  
    n 0 
    d 0 
    a 0
    y 0
	return 0;
}