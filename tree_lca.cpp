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

bool findPath(Node *node, int k, vector <int> &path){
	if (node==NULL){
		return false;
	}
	path.push_back(node->data);
	if (node->data==k){
		return true;
	}
	if ((node->left && findPath(node->left, k, path)) || (node->right && findPath(node->right, k, path))){
		return true;
	}
	path.pop_back();
	return false;
}

int findLCA(Node *root, int k1, int k2){
	vector <int> path1, path2;

	if(!findPath(root,k1, path1)|| !findPath(root, k2, path2)){
		return -1;
	}
	int i;
	for (i=0;i<path1.size() &&i<path2.size();i++){
		if(path1[i]!=path2[i]) break;
	}
	return path1[i-1];
}

Node * findLCA_Method2(Node *node, int k1, int k2){
	if (node==NULL) return NULL;

	if (node->data==k1|| node->data==k2){
		return node;
	}

	Node * Left_lca = findLCA_Method2(node->left, k1, k2);
	Node * Right_lca = findLCA_Method2(node->right, k1, k2);
	if (Left_lca && Right_lca) return node;
	else if (Left_lca){
		return Left_lca;
	}
	else{
		return Right_lca;
	}
}

Node *findLCA_forBST(Node *root, int n1, int n2){
	if (root==NULL){
		return NULL;
	}
	if (root->data>n1 && root->data>n2){
		return findLCA_forBST(root->left,n1,n2);
	}
	if (root->data<n1 && root->data<n2){
		return findLCA_forBST(root->right,n1,n2);
	}
	return root;
}

int distance_two_nodes(Node *root, int dest, int k){
	if (root==NULL){
		return -1;
	}
	if (root->data==dest){
		return k;
	}
	k++;
	int lDis = distance_two_nodes(root->left, dest, k);
	int rDis = distance_two_nodes(root->right, dest, k);
	if (lDis!=-1){
		return lDis;
	}
	else if (rDis!=-1){
		return rDis;
	}
	else{
		return -1;
	}
}



int min_distance_between_two_nodes(Node *root,int n1, int n2){
	Node *lca  =findLCA_Method2(root, n1, n2);
	int d1 = distance_two_nodes(lca, n1, 0);
	int d2 = distance_two_nodes(lca, n2, 0);
	return d1+d2;
}


int main(int argc, char const *argv[])
{	
	// Node * root = createNewNode(1);
 //    root->left = createNewNode(2);
 //    root->right = createNewNode(3);
 //    root->left->left = createNewNode(4);
 //    root->left->right = createNewNode(5);
 //    root->right->left = createNewNode(6);
 //    root->right->right = createNewNode(7);
    // cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    // cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    // cout << "\nLCA(3, 4) = " << findLCA_Method2(root, 3, 4)->data;
    // cout << "\nLCA(2, 4) = " << findLCA_Method2(root, 2, 4)->data;
    // cout<<distance_two_nodes(root, 4, 0)<<endl;
    // cout<<min_distance_between_two_nodes(root, 4,7)<<endl;

    Node  *root        = createNewNode(20);
    root->left               = createNewNode(8);
    root->right              = createNewNode(22);
    root->left->left         = createNewNode(4);
    root->left->right        = createNewNode(12);
    root->left->right->left  = createNewNode(10);
    root->left->right->right = createNewNode(14);

    cout<<findLCA_forBST()<<endl;
	return 0;
}