#include <bits/stdc++.h>
using namespace std;
#define new_line cout<<endl


struct Node{
	int data;
	Node* left;
	Node *right;
};

Node *createNewNode(int data){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data  = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node * insert(Node *node, int key){
	if (node==NULL) return createNewNode(key);
	if (key<node->data){
		node->left = insert(node->left, key);
	}
	else if (key>node->data){
		node->right = insert(node->right, key);
	}
	return node;
}

Node * search(Node *node,int key){
	if (node==NULL){
		return NULL;
	}
	if (node->data==key){
		return node;
	}
	else if (key<node->data){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);	
	}
	
}

void inorder(Node *node){
	if (node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

/*
No of bst's with n distinct keys are catalan number = (2n!) / n! * (n+1)!
No of binary trees with n distinct keys = catalan number * n!
*/

Node *minNode(Node *root){
	Node *temp = root;
	while (temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

Node * deleteNode(Node *node, int key){
	if (node==NULL){
		return NULL;
	}
	else if (key< node->data){
		node->left = deleteNode(node->left, key);
	}
	else if (key> node->data){
		node->right = deleteNode(node->right, key);
	}
	else{
		if (node->left==NULL){
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right==NULL){
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node *temp = minNode(node->right);
		node->data = temp->data;
		deleteNode(node->right, temp->data);
	}
	return node;
}


Node * bst_from_preorder(int pre[], int n){
	if (n==0){
		return NULL;
	}
	Node *node  = createNewNode(pre[0]);
	int index=-1, li=1;
	for (int i=1;i<n;i++){
		if (pre[i]>pre[0]){
			index= i;
			break;
		}
	}
	if (n==1){
		return node;
	}
	if (index!=-1){
		node->left = bst_from_preorder(pre+1, index-1);
		node->right = bst_from_preorder(pre+index, n-index);	
	}
	else{
		node->left = bst_from_preorder(pre+1, n-1);
	}
	return  node;
}


// Node * bst_from_preorder_better_method_util(int pre,  int &preI,int key,int min, int max , int size ){

// 	if (	preI>=size){
// 		return NULL;
// 	}
// 	Node *node =NULL;
// 	if (key>min && key<max){
// 		node = createNewNode(key);
// 		preI = preI+1;
// 		node->left = bst_from_preorder_better_method_util(pre, preI, pre[preI], min, key, size);
// 		node->right = bst_from_preorder_better_method_util(pre, preI,pre[preI], key, max, size);
// 	}	
// 	return node;
// }

// Node * bst_from_preorder_better_method(int pre[], int n){
// 	int preI = 0;
// 	return bst_from_preorder_better_method_util(pre, preI,pre[0], 	INT_MIN,INT_MAX, n); 
// }

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void  min(int a, int b){
	return a<b?a:b;
}

void  max(int a, int b){
	return a>b?a:b;
}

// void convertToBST(Node *node){
// 	if (node==NULL || node->left==NULL && node->right==NULL){
// 		return;
// 	}

// 	convertToBST(node->left);
// 	convertToBST(node->right);

// 	int data_left=INT_MIN, data_right=INT_MAX;

// 	if (node->left) data_left= node->left->data;
// 	if (node->right) data_right = node->right->data;

// 	if (node->data > data_left && node->data<data_right){
// 		return;
// 	}
// 	else{
// 		if (data_left!=INT_MIN && data_right!=INT_MAX){
// 			int min_of_three = min(node->data, min(data_left, data_right));
// 			int max_of_three = max(node->data, max(data_left, data_right));
// 		}
// 	}
// }


int main(int argc, char const *argv[])
{
	// Node *root = NULL;
	// root = insert(root, 50);
	// insert(root, 30);
	// insert(root, 20);
	// insert(root, 40);
	// insert(root, 70);
	// insert(root, 60);
	// insert(root, 80);
    // inorder(root);
    // cout<<endl;
  	// cout<<search(root, 60)->data<<endl;
  	// cout<<minNode(root)->data<<endl;
  	// deleteNode(root,50);
	// inorder(root);
	// new_line;


	//Construction of BST
	// int pre[] = {10, 5, 1, 7, 40, 50};
	// int n  = 6;
	// Node * root = bst_from_preorder(pre, n);
	// inorder(root); new_line;
	// Node * root = bst_from_preorder_better_method(pre, n);
	// inorder(root); new_line;

	//Tree to BST
	Node *root = createNewNode(10);
    root->left = createNewNode(30);
    root->right = createNewNode(15);
    root->left->left = createNewNode(20);
    root->right->right = createNewNode(5);
    inorder(root); new_line;
    convertToBST(root);
    inorder(root); new_line;
	return 0;
}