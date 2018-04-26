#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node * next;
};

Node * newNode(int data){
	Node * node  = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void addNewNode(Node *head, int data){
	Node *node = newNode(data);
	if (head->next==NULL){
		head->next = node;
	}
	else{
		Node *temp = head->next;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = node;		
	}

	cout<<"Node with "<<data<<" added.\n";
}

void printList(Node *head){
	Node *temp = head->next;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insertAtFront(Node *head,int data){
	Node *node = newNode(data);
	node->next = head->next;
	head->next =node;
}

void insertAfter(Node * head,int data, int newData){
	Node *temp = head->next;
	while(temp->data!=data){
		temp=temp->next;
	}
	Node *node = newNode(newData);
	node->next = temp->next;
	temp->next=node;
}

void del(Node *head, int data){
	Node * temp = head->next;
	while(temp->next !=NULL && temp->next->data!=data){
		temp=temp->next;
	}
	Node *temp1 = temp->next->next;
	free(temp->next);
	temp->next = temp1;
}

int len(Node *node, int l){
	if (node->next==NULL){
		return l;
	}
	else{
		return len(node->next, l+1);
	}
}



int main(int argc, char const *argv[])
{
	Node *head = newNode(INT_MIN);

	addNewNode(head, 1);
	addNewNode(head, 2);
	addNewNode(head, 3);
	insertAtFront(head, 0);
	insertAfter(head, 2, 45);
	del(head, 	3);
	printList(head);
	cout<<len(head,0)<<endl;
	return 0;
}