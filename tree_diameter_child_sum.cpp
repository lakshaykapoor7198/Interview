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


int max(int a,int b){
	return (a>b?a:b);
}

int height(Node *root){
	if (root==NULL){
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return (lh>rh?lh+1:rh+1);
}

int diameter(Node *root){
	if (root==NULL){
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	int lDia = diameter(root->left);
	int rDia = diameter(root->right);
	return max(lh+rh+1, max(lDia, rDia));
}


bool child_sum_property(Node *root){
	if (root->left==NULL && root->right==NULL){
		return true;
	}
	int l,r;
	l  =(root->left?root->left->data:0);
	r  =(root->right?root->right->data:0);
	cout<<l<<" "<<r<<" "<<root->data<<endl;
	if (root->data== l+r){
		bool lh=true, rh=true;
		if (root->left){
			lh = child_sum_property(root->left);
		}
		if (root->right){
			rh = child_sum_property(root->right);
		}
		if (lh&&rh){
			return true;
		}
	}
	return false;
}

void all_paths_from_root_to_leaf(Node *root, vector <int> &v){
	if (root->left==NULL && root->right==NULL){
		for (int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<root->data;
		cout<<endl;
		return;
	}
	v.push_back(root->data);
	if (root->left)		all_paths_from_root_to_leaf(root->left,v);
	if (root->right) 	all_paths_from_root_to_leaf(root->right,v);
	v.pop_back();
}


int main(int argc, char const *argv[])
{	
	// Node *root = createNewNode(1);
	// root->left        = createNewNode(2);
	// root->right       = createNewNode(3);
	// root->left->left  = createNewNode(4);
	// root->left->right = createNewNode(5);
    // cout<<diameter(root)<<endl;
    
	Node *root  = createNewNode(10);
	root->left         = createNewNode(8);
	root->right        = createNewNode(2);
	root->left->left   = createNewNode(3);
	root->left->right  = createNewNode(5);
	root->right->right = createNewNode(2);
    // cout<<child_sum_property(root)<<endl;
	vector <int> v;
    all_paths_from_root_to_leaf(root, v);
	return 0;
}