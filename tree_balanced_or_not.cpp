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
int minHeight = INT_MAX;
int maxHeight = INT_MIN;

void calc_Height(Node *root, int k){
	if (root==NULL){
		return;
	}
	if (minHeight>k){
		minHeight = k;
	}
	if (maxHeight<k){
		maxHeight=k;
	}
	k++;
	calc_Height(root->left, k);
	calc_Height(root->right,k);
}

bool isBalanced(Node *root){
	calc_Height(root,0);
	if (maxHeight-minHeight>1){
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{	
	Node *root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->left->left->left = createNewNode(8);
    cout<<isBalanced(root)<<endl;
	return 0;
}