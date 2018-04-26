#include <bits/stdc++.h>
using namespace std;

struct Stack {
	int top;
	int * arr;
	int capacity;
};

Stack * init(int cap){
	Stack * node = (Stack *) malloc(sizeof(Stack *));
	node->capacity= cap;
	node->top=-1;
	node->arr = (int *) malloc(cap*sizeof(int));
	return node;
}

void push(int data, Stack *s){
	if (s->top>=s->capacity-1){
		cout<<"Overflow \n";
		return;
	}
	s->arr[++s->top] =  data;
	cout<<data<<" pushed \n";
}

int pop(Stack *s){
	if (s->top<0){
		cout<<"Underfow \n";
		return -9999;
	}
	int x = s->arr[s->top--];
	return x;
}

int main(int argc, char const *argv[])
{
	Stack *s = init(4);
	push(1,s);
	push(2,s);
	push(3,s);
	push(4,s);
	push(5,s);
	cout<<pop(s)<<" popped "<<endl;
	cout<<pop(s)<<" popped "<<endl;
	cout<<pop(s)<<" popped "<<endl;
	cout<<pop(s)<<" popped "<<endl;
	cout<<pop(s)<<" popped "<<endl;
	return 0;
}