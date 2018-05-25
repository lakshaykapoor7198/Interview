#include <bits/stdc++.h>
using namespace std;

#define forLoop(i,s, n) for (int i=s;i<n;i++)


void printArray(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

struct HeapNode{
	char a;
	int freq;
	HeapNode *left, *right;
};

struct Heap{
	int capacity;
	int curr;
	struct HeapNode **arr;
};

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	return (i-1)/2;
}

HeapNode* getMin(Heap *heap){
	HeapNode* h = heap->arr[0];
	return h;
}

Heap *createNewHeap(int n){
	Heap *heap = (Heap *) malloc(sizeof(Heap));
	heap->capacity = n;
	heap->curr = 0;
	heap->arr = (HeapNode **) malloc(n*sizeof(HeapNode *));
	return heap; 
}

void swapNodes(HeapNode **a, HeapNode **b){
	HeapNode *t = *a;
	*a =*b;
	*b = t;
}

HeapNode * createNewHeapNode(char a, int freq, HeapNode *node1, HeapNode *node2){
 	HeapNode *h = (HeapNode *) malloc(sizeof(HeapNode));
 	h->a = a;
 	h->freq = freq;
 	h->left =node1;
 	h->right =node2;
 	return h;
}

void insert(Heap *heap,int a, int freq, HeapNode *node1, HeapNode *node2){
	int i = heap->curr;
	heap->arr[i] = createNewHeapNode(a, freq, node1, node2);
	heap->curr++;
	while (i!=0 && heap->arr[i]->freq<heap->arr[parent(i)]->freq){
		swapNodes(&heap->arr[i],&heap->arr[parent(i)]);
		i = parent(i);
	}
}

void minHeapify(Heap *heap, int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l<heap->curr && heap->arr[l]->freq<heap->arr[smallest]->freq){
		smallest=l;
	}
	if (r<heap->curr && heap->arr[r]->freq<heap->arr[smallest]->freq){
		smallest=r;
	}
	
	if (smallest!=i){
		swapNodes(&heap->arr[smallest], &heap->arr[i]);
		minHeapify(heap, smallest);
	}
	
}

HeapNode *extractMin(Heap *heap){
	if (heap->curr==0){
		return NULL;
	}
	if (heap->curr==1){
		heap->curr--;
		return heap->arr[0];
	}
	HeapNode* temp = heap->arr[0];
	swapNodes(&heap->arr[0], &heap->arr[(heap->curr)-1]);
	heap->curr--;

	minHeapify(heap, 0);
	return temp;
}

bool isHeapSizeOne(Heap *heap){
	return (heap->curr==1);
}

void printHeap(Heap *heap){
	cout<<"HEAP PRINT STARTS"<<endl;
	for (int i=0;i<heap->curr;i++){
		cout<<heap->arr[i]->a<<" "<<heap->arr[i]->freq<<endl;
	}
	cout<<"HEAP PRINT STOPS"<<endl;
}


HeapNode * buildTreeHuffman(char charArray[], int freqArray[], int n){
	Heap *heap = createNewHeap(n);
	forLoop(i, 0, n){
		insert(heap, charArray[i], freqArray[i], NULL, NULL);
	}
	while (!isHeapSizeOne(heap)){
		HeapNode* node1 = extractMin(heap);
		HeapNode* node2 = extractMin(heap);
		insert(heap, '$', node1->freq+node2->freq , node1, node2);
	}
	return extractMin(heap);

}

void bfs_queue_at_level(HeapNode *root){
	int i;
	queue <HeapNode *> q;
	q.push(root);
	while (!q.empty()){
		
		int count = q.size();
		while (count>0){
			HeapNode *node = q.front();
			q.pop();
			cout<<node->a<<" "<<node->freq<<" : ";
			if (node->left)		q.push(node->left);
			if (node->right)	q.push(node->right);
			count--;
		}
		cout<<endl;
	}
}

void HuffmanCodes(HeapNode *node, vector <int > &v){
	if (node->a!='$'){
		cout<<node->a<<" : ";
		forLoop(i,0, v.size()){
			cout<<v[i]<" ";
		}
		cout<<endl;
		return;
	}
	if (node->left) {
		v.push_back(0);
		HuffmanCodes(node->left, v);
		v.pop_back();
	}
	if (node->right) {
		v.push_back(1);
		HuffmanCodes(node->right, v);
		v.pop_back();
	}
	
	
}

int main(int argc, char const *argv[])
{
	char charArray[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freqArray[] = { 5, 9, 12, 13, 16, 45 };
    int n = sizeof(charArray)/sizeof(charArray[0]);
    HeapNode* root=buildTreeHuffman(charArray, freqArray, n);
    vector <int> v;
    HuffmanCodes(root, v);
	return 0;
}