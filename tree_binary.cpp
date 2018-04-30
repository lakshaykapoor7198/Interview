#include <bits/stdc++.h>
using namespace std;

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

void preorder(Node *node){
	if (node==NULL){
		return;
	}
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}

void postorder(Node *node){
	if (node==NULL){
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
}


int recuriveHeight(Node *node){

}

int height(Node *node){
	if (node==NULL){
		return 0;
	}
	else{
	 	int lheight = height(node->left);
	 	int rheight = height(node->right);
	 	if (lheight>rheight){
	 		return lheight+1;
	 	}
	 	else{
	 		return rheight+1;
	 	}
	}
}


int main(int argc, char const *argv[])
{
	Node *root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(4);
	root->left->right = createNewNode(5);
	// inorder(root);
	// cout<<endl;
	// preorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// cout<<height(root)<<endl;
	return 0;
}