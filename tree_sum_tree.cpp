#include <bits/stdc++.h>
using namespace std;
#define N 6

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node * createNewNode(int data){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->left= NULL;
	node->right = NULL;
	return node;
}

void inorder(Node *node){
	if (node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

int sum_tree(Node *node){
	int temp  =node->data;
	if (node->left==NULL&& node->right==NULL){
		node->data=0;
		return temp;
	}

	int lSum = sum_tree(node->left);
	int rSum  = sum_tree(node->right);

	node->data = lSum+rSum;
	// cout<<node->data<<" "<<lSum<<" "<<rSum<<endl;
	return node->data + temp;
}


void bfs_queue(Node *root){
	int i;
	queue <Node *> q;
	q.push(root);
	while (!q.empty()){
		Node *node = q.front();
		q.pop();
		cout<<node->data<<" ";
		if (node->left)		q.push(node->left);
		if (node->right)	q.push(node->right);
	}
	cout<<endl;
}



int main(int argc, char const *argv[])
{	
	Node *root = createNewNode(10);
	root->left = createNewNode(-2);
	root->right = createNewNode(6);
	root->left->left = createNewNode(8);
	root->left->right = createNewNode(-4);
	root->right->left = createNewNode(7);
	root->right->right = createNewNode(5);
	sum_tree(root);
	bfs_queue(root);
	return 0;
}