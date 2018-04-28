#include <bits/stdc++.h>
using namespace std;

struct Node {
	void *data;
	Node *next;
};

Node * createNewNode(void *data, size_t data_size){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = malloc(data_size);

	for (int i=0;i<data_size;i++){
		*(char *)(node->data + i) = *(char *)(data+i);
	}
	node->next = NULL;
	return node;
}


void push(Node *head, void *data, size_t data_size){
	Node * node = createNewNode(data, data_size);
	node->next=  head->next;
	head->next = node;
}

void printList(Node *head, void (*fptr)(void *)){
	Node *node = head->next;
	while (node!=NULL){
		(*fptr)(node->data);
		node=node->next;
	}
	cout<<endl;
}


void printInt(void *data){
	printf("%d ", *(int *)data);
}

void printFloat(void *data){
	printf("%f ", *(float *)data);
}

int main(int argc, char const *argv[])
{
	unsigned int_size = sizeof(int);
	int a = 10;
	Node *head=createNewNode(&a, int_size);
	int arr[] = {1,2,3,4,5};
	for (int i=0;i<5;i++){
		push(head, &arr[i], int_size);
	}
	printList(head, printInt);
	

	unsigned float_size = sizeof(float);
	float a1 = 10.0;
	Node *head1=createNewNode(&a1, float_size);
	int arr1[] = {10.1,2.1,3.2,4.1,5.4};
	for (int i=0;i<5;i++){
		push(head1, &arr1[i], float_size);
	}
	printList(head1, printFloat);

	return 0;
}