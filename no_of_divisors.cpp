
#include <bits/stdc++.h>

using namespace std;

long long int noOfDivisors(int n){
    long long int count=0;
    for (long long int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if (n==i*i) count++;
            else count+=2;    
        }
    } 
    return count;
}

int main() {
    long long int t;
    cin>>t;
    while (t--){
        long long int l,r;
        cin>>l>>r;
        long long int count=0;
        for (int i=l;i<=r;i++){
            if (i==1) count++;
            else{
                if (noOfDivisors(i)&1==1){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}