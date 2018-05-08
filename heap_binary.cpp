#include <bits/stdc++.h>
using namespace std;

struct Heap{
	int capacity;
	int curr;
	int *arr;
};

int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return (2*i +1);
}

int right(int i){
	return (2*i +2);
}

int getMin(Heap *h){
	return h->arr[0];
}

Heap * createNewHeap(int capacity){
	Heap *h =(Heap *) malloc(sizeof(Heap));
	h->capacity = capacity;
	h->curr= 0;
	h->arr = (int *) malloc(capacity*sizeof(int));
	return h;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(Heap *h, int data){
	if (h->curr == h->capacity){
		cout<<"Heap Full\n";
		return;
	}
	h->arr[h->curr]=data;
	int i = h->curr;
	while (i!=0 && h->arr[i]<h->arr[parent(i)]){
		swap(&h->arr[i], &h->arr[parent(i)]);
		i = parent(i);
	}
	h->curr++;
}


void decreaseKey(Heap *h, int i, int data){
	h->arr[i]=data;
	while (i!=0 && h->arr[i]<h->arr[parent(i)]){
		swap(&h->arr[i], &h->arr[parent(i)]);
		i = parent(i);
	}
}


void MinHeapify(Heap *h, int i){
	int l =left(i);
	int r = right(i);
	int smallest=i;
	if (l<h->curr && h->arr[l]<h->arr[i]){
		smallest = l;
	}
	if (r<h->curr && h->arr[r]<h->arr[smallest]){
		smallest = r;
	}
	if (smallest!=i){
		swap(&h->arr[i], &h->arr[smallest]);
		MinHeapify(h,smallest);
	}
}

int extractMin(Heap *h){
	int temp = h->arr[0];
	h->arr[0] = h->arr[h->curr-1];
	h->curr--;
	MinHeapify(h,0);
	return temp;
}

void deleteKey(Heap *h, int i){
	decreaseKey(h, i, INT_MIN);
	extractMin(h);
}

void showHeap(Heap *h){
	for (int i=0;i<h->curr;i++){
		cout<<h->arr[i]<<" ";
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	// Heap * h = createNewHeap(5);
	// insert(h,1);
	// insert(h,2);
	// insert(h,3);
	// insert(h,4);
	// insert(h,5);
	// insert(h,6);
	// showHeap(h);
	// cout<<getMin(h)<<endl;
	// cout<<extractMin(h)<<endl;
	// showHeap(h);
	// decreaseKey(h, 1, 1);
	// showHeap(h);
	// deleteKey(h,1);
	// showHeap(h);
	return 0;
}