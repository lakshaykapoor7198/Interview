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

Node * mirror_tree(Node *node){
	if (node->left==NULL && node->right==NULL){
		return node;
	}
	Node *l = mirror_tree(node->left);
	Node *r = mirror_tree(node->right);
	node->left = r;
	node->right  =l;
	return node;
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
	Node *root = createNewNode(1);
	root->left  = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left  = createNewNode(4);
	root->left->right = createNewNode(5); 
	inorder(root);
	cout<<endl;
	root = mirror_tree(root);
	inorder(root);
	cout<<endl;
	return 0;
}