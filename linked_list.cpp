#include <bits/stdc++.h>
#include <initializer_list>
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

void mid(Node *head){
	Node *temp1 = head->next;
	Node *temp2= head->next;
	while (temp2!=NULL && temp2->next!=NULL){
		temp2 = temp2->next->next;
		temp1= temp1->next;
	}
	cout<<temp1->data<<endl;
}


void midGood(Node *head){
	Node *mid = head;
	Node *temp = head->next;
	int count=1;
	while(temp->next!=NULL){
		if (count & 1){
			mid = mid->next;
		}
		count++;
		temp = temp->next;
	}
	cout<<mid->next->data<<endl;
}

bool floydLoop(Node *head){
	Node *temp1 = head->next;
	Node *temp2= head->next;
	while (temp2!=NULL && temp2->next!=NULL){
		temp2 = temp2->next->next;
		temp1= temp1->next;
		if (temp1==temp2){
			return true;
		}
	}
	return false;
}


// bool loopVisited(Node *head){
// 	unordered_set <Node *> s;
// 	Node * temp = head->next;
// 	while(temp->next!=NULL){
		
// 		if (s.find(temp)!=s.end()){
// 			return true;
// 		}
// 		s.insert(temp);
// 		temp=temp->next;

// 	}
// 	return false;
// }

void rev(Node *head){
	Node *temp = head->next;
	Node *prev = NULL;
	while (temp!=NULL){
		Node *n = temp->next;
		temp->next = prev;
		prev = temp;
		temp = n;
	}
	head->next = prev;
}

//To check for palindrome, find reverse and if both equal  


bool palindrome(Node ** left, Node *right){
	
	if (right==NULL){
		return true;
	}

	bool val = palindrome(left, right->next);
	if (val==false) return false;
	cout<<(*left)->data<<" "<<right->data<<"\n";
	if((*left)->data == right->data){
		*left = (*left)->next;
		return true;
	}
	else {
		return false;
	}
}


void recurRev(Node *node){
	if (node==NULL){
		return;
	}
	recurRev(node->next);
	cout<<node->data<<" "; 
}

void removeDup(Node *head){
	Node *temp = head->next;
	Node *prev = head;
	while (temp->next!=NULL){
		Node *n = temp->next;
		if (temp->data == n->data){
			prev->next = n;
			free(temp);
		}
		else{
			prev = temp;
		}
		temp = n;
	}
}

void removeDupUnsorted(Node *head){
	Node *temp = head->next;
	Node *prev= head;
	unordered_set <int> s;
	while (temp!=NULL){
		Node *n = temp->next;
		if (s.find(temp->data)!=s.end()){
			prev->next = n;
			free(temp);
		}
		else{
			s.insert(temp->data);
			prev = temp;
		}
		temp = n;
	}
}

void alternate(Node *head){
	Node *temp = head->next;
	Node *prev= head;
	int count=0;
	while (temp!=NULL){
		Node *n = temp->next;
		if (count & 1){
			prev->next = n;
			free(temp);
		}
		else{
			prev = temp;
		}
		count++;
		temp = n;
	}
}

void reverseGroups(Node *head, int k){
	Node *temp = head->next;
	Node *prev = NULL;
	Node *hPrev1 = NULL;
	Node *hPrev2 = NULL;
	int count=1;
	int flag  = 0;
	while(temp!=NULL){
		Node *n = temp->next;
		temp->next = prev;
		prev =temp;
		if (count==k){
			head->next = temp;
			flag = 1;
		}
		else if (count%k==1 && n==NULL){
			if (flag == 0){
				hPrev2->next = temp;
				flag =1;
			}
			else{
				hPrev1->next = temp;
				flag =0;
			}
		}
		else if (count%k==1 && flag==0 && n!=NULL){
			hPrev1= temp;
		}
		else if (count%k==1 && flag==1 && n!=NULL){
			hPrev2 = temp;
		}
		else if (n==NULL && count%k!=0){
			if (flag == 0){
				hPrev2->next = temp;
				hPrev2 = temp;
				flag =1;
			}
			else{
				hPrev1->next = temp;
				hPrev1 = temp;
				flag =0;
			}	
		}
		else if (count!=k && count%k==0){
			if (flag == 0){
				hPrev2->next = temp;
				flag =1;
			}
			else{
				hPrev1->next = temp;
				flag =0;
			}
		}
		temp = n;
		count++;
	}
	if (flag == 0){
		hPrev2->next = NULL;
	}
	else{
		hPrev1->next = NULL;
	}
}


int main(int argc, char const *argv[])
{
	Node *head = newNode(INT_MIN);

	addNewNode(head, 1);
	addNewNode(head, 2);
	addNewNode(head, 3);
	addNewNode(head, 4);
	addNewNode(head, 5);
	addNewNode(head, 6);
	addNewNode(head, 7);
	// addNewNode(head, 8);
	// addNewNode(head, 9);
	// insertAtFront(head, 0);
	// insertAfter(head, 2, 45);
	// del(head, 	3);
	// removeDup(head);
	// removeDupUnsorted(head);
	// alternate(head);
	printList(head);
	reverseGroups(head, 3);
	printList(head);
	// rev(head);
	// printList(head);
	// cout<<len(head,0)<<endl;
	// midGood(head);
	// cout<<floydLoop(head);
	// cout<<loopVisited(head);
	// cout<<palindrome(&head->next,head->next)<<endl;4
	// recurRev(head->next);
	// cout<<"\n";
	return 0;
}	