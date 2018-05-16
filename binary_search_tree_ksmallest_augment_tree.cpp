#include <bits/stdc++.h>
using namespace std;
#define new_line cout<<endl


struct Node{
	int data;
	int left_count;
	Node* left;
	Node *right;
};

Node *createNewNode(int data, int left_count){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data  = data;
	node->left_count = left_count;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node * insert(Node *node, int key, int left_count=0){
	if (node==NULL) return createNewNode(key, left_count);
	if (key<node->data){
		node->left_count++;
		node->left = insert(node->left, key);
	}
	else if (key>node->data){
		node->right = insert(node->right, key);
	}
	return node;
}

void inorder(Node *node){
	if (node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" "<<node->left_count<<endl;
	inorder(node->right);
}

Node * kth_smallest(Node *root, int k){
	if (root==NULL){
		return NULL;
	}
	if (k==root->left_count+1){
		return root;
	}
	if (k <= root->left_count){
		return kth_smallest(root->left, k);
	}
	else{
		return kth_smallest(root->right, k-root->left_count-1);
	}
}

int main(int argc, char const *argv[])
{
	// Node *root 		  = createNewNode(4);
	// root->left        = createNewNode(2);
	// root->right       = createNewNode(5);
	// root->left->left  = createNewNode(1);
	// root->left->right = createNewNode(3);
    // cout<<isBST(root)<<endl; 
    // cout<<kth_smallest(root, 6)->data<<endl;
    Node *root = insert(NULL, 41);
    insert(root, 21);
    insert(root, 51);
    insert(root, 11);
    insert(root, 31);
    // inorder(root); new_line;
    cout<<kth_smallest(root, 2)->data; new_line;
	return 0;
}