#include <bits/stdc++.h>
using namespace std;

struct Queue{
	int front,rear,size,capacity;
	int *arr;
};

Queue * createQueue(int capacity){
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->size=0;
	q->front = 0;
	q->rear=-1;
	q->capacity = capacity;
	q->arr = (int *) malloc(capacity*sizeof(int));
	return q;
}

void enq(int data, Queue* q){
	if (q->size==q->capacity){
		cout<<"Queue full\n";
		return;
	}
	q->rear = (q->rear+1)%q->capacity;
	q->arr[q->rear] = data;
	q->size++;
	cout<<data<<" pushed.\n";
}

void printArray(Queue* q){
	for (int i=0;i<q->capacity;i++){
		cout<<q->arr[i]<<" ";
	}
	cout<<"\n";
}

int deq(Queue *q){
	if (q->size==0){
		cout<<"queue Empty\n";
		return INT_MIN;
	}
	int x = q->arr[q->front];
	q->front = (q->front+1)%q->capacity;
	q->size--;
	return x;
}

int main(int argc, char const *argv[])
{
	Queue *q = createQueue(4);
	enq(1,q);
	enq(2,q);
	enq(3,q);
	enq(4,q);
	enq(5,q);
	cout<<deq(q)<<"popped\n";
	cout<<deq(q)<<"popped\n";	

	return 0;
}