#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long int n;
	cin>>n;
	long int arr[n];
	long int i,j;	
	for (i=0;i<n;i++){
		cin>>arr[i];
	}
	long int c = 0;
	long int l=0;
	long int r=0;

	for (i=1;i<n-1;i++){
	    
		l=0;
		r=0;
		for (j=0;j<n;j++){
			if (i!=j && arr[i]>arr[j]){
				if (j<i){
					l+=1;
				}		
				if (j>i){
					r+=1;
				}		
			}
		}
		c = c + l*r;
	}
	cout<<c<<endl;
	return 0;
}