#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
};

Node * createNewNode(int data){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void push(int data, Node *head){
	Node *node = createNewNode(data);
	node->next = head->next;
	head->next=node;
	cout<<data<<" pushed\n";
}

int pop(Node *head){
	if (head->next==NULL){
		cout<<"Underflow \n";
		return INT_MIN;
	}
	Node *node = head->next;
	head->next = node->next;
	int x = node->data;
	free(node);
	return x;

}

int main(int argc, char const *argv[])
{
	Node *head = createNewNode(0);
	push(1,head);
	push(2,head);
	push(3,head);
	push(4,head);
	push(5,head);
	cout<<pop(head)<<" popped "<<endl;
	cout<<pop(head)<<" popped "<<endl;
	cout<<pop(head)<<" popped "<<endl;
	cout<<pop(head)<<" popped "<<endl;
	cout<<pop(head)<<" popped "<<endl;
	return 0;
}