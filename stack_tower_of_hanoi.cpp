#include <bits/stdc++.h>
using namespace std;



void show(stack <int> s){
	stack <int> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<"\n";
}

void moveDisk1(int x, char s, char d){
	cout<<"Moved "<<x<<" from "<<s<<" to "<<d<<endl;
}

void moveDisk(stack <int> &src, stack <int> &dest, char s, char d){
	int x;
	if (src.empty()){
		x = dest.top();
		dest.pop();
		src.push(x);
		moveDisk1(x, d,s);
	}
	else if (dest.empty()){
		x = src.top();
		src.pop();
		dest.push(x);
		moveDisk1(x,s, d);
	}
	else if (src.top()<dest.top()){
		x  =src.top();
		src.pop();
		dest.push(x);
		moveDisk1(x,s, d);
	}
	else{
		x  =dest.top();
		dest.pop();
		src.push(x);
		moveDisk1(x, d,s);
	}

}

void toh(stack <int> src, stack <int> dest, stack <int> aux, int numOfDisk){
	if (numOfDisk%2==0){
		stack <int> temp = dest;
		dest = aux;
		aux = temp;
	}
	int i;
	for (i=numOfDisk;i>=1;i--){
		src.push(i);
	}
	for (i=1;i<=(pow(numOfDisk,2)-1);i++){
		
		if (i%3==1){
			moveDisk(src, dest, 'S', 'D');
		}
		if (i%3==2){
			moveDisk(src, aux, 'S', 'A');
		}
		if (i%3==0){
			moveDisk(dest, aux, 'D', 'A');
		}
	}
	show(src);
	show(dest);
	show(aux);
}

int main(int argc, char const *argv[])
{
	stack <int> src;
	stack <int> dest;
	stack <int> aux;
	int numOfDisk = 3;
	toh(src, dest, aux, numOfDisk);
	return 0;
}