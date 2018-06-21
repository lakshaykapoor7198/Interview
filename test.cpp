#include <bits/stdc++.h>
using namespace std;

int returnOrder(char c){
    if (c=='!') return 0;
    if (c=='#') return 1;
    if (c=='$') return 2;
    if (c=='%') return 3;
    if (c=='&') return 4;
    if (c=='*') return 5;
    if (c=='@') return 6;
    if (c=='^') return 7;
    if (c=='~') return 8;
}


int main() {
    int t;
    cin>>t;
    while (t--){
        int n,i,j,nut, max_diff, index, bolt;
        cin>>n;
        char c;
        vector <int> nuts(n), bolts(n), res(n);
        vector <int>::iterator it;
        for (i=0;i<n;i++){
            cin>>c;
            nuts[i]=returnOrder(c);
        }
        for (i=0;i<n;i++){
            cin>>c;
            bolts[i]=returnOrder(c);
        }
        
        for (i=0;i<n;i++){
            nut= nuts[i];
            max_diff=INT_MIN;
            for (j=0;j<n-i;j++){
                bolt = bolts[j];
                if (nut-bolt>max_diff){
                    max_diff = nut-bolt;
                    index= j;
                }
            }
            res[i] = bolts[index];
            cout<<res[i]<<endl;
            // it = bolts.begin();
            // bolts.erase(it+j);
        }
        for (int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        
    }
    return 0;
}