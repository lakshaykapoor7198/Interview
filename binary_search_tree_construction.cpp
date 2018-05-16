#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void inorder(Node *node){
	if (node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

void show(stack <Node *> s){
	stack <Node *> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()->data<<" ";
		s1.pop();
	}
	cout<<"\n";
}

Node *createNewNode(int data){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data  = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node * bst_from_pre(int pre[], int n){
	if (n==1){
		Node *node = createNewNode(pre[0]);
		return node;
	}
	Node *node = createNewNode(pre[0]);
	int index_right=-1;
	for (int i=0; i<n; i++){
		if (pre[i]>pre[0]){
			index_right=i;
			break;
		}
	}

	if(index_right==-1){
		node->left=bst_from_pre(pre+1, n-1);
	}
	else if(index_right==1){
		node->right=bst_from_pre(pre+1 ,n-1);
	}
	else{
		node->left=bst_from_pre(pre+1, index_right-1);
		node->right=bst_from_pre(pre+index_right, n- index_right);
	}
	return node;
}


Node *bst_from_pre_order_n_util(int pre[], int *preIndex, int min, int max, int n){
	if (*preIndex>=n){
		return NULL;
	}
	Node *node  = NULL;
	if (pre[*preIndex]>min && pre[*preIndex]<max){
		node  =createNewNode(pre[*preIndex]);
		*preIndex  = *preIndex +1;
		node->left = bst_from_pre_order_n_util(pre, preIndex, min, node->data-1, n);
		node->right = bst_from_pre_order_n_util(pre, preIndex, node->data+1, max, n);
	}
	return node;
}

Node *bst_from_pre_order_n(int pre[], int n){
	int preIndex = 0;
	return bst_from_pre_order_n_util(pre, &preIndex,INT_MIN, INT_MAX, n);
}

void bfs_queue_at_level(Node *root){
	int i;
	queue <Node *> q;
	q.push(root);
	while (!q.empty()){
		
		int count = q.size();
		while (count>0){
			Node *node = q.front();
			q.pop();
			cout<<node->data<<" ";
			if (node->left)		q.push(node->left);
			if (node->right)	q.push(node->right);
			count--;
		}
		cout<<endl;
	}
}


Node *bst_from_pre_stack(int pre[], int n){
	stack <Node *> s;
	Node *root, *node, *temp;
	root = createNewNode(pre[0]);
	s.push(root);
	for (int i=1;i<n;i++){
		node  = createNewNode(pre[i]);
		if (s.top()->data>pre[i]){
			s.top()->left = node;
			s.push(node);
		}
		else{
			while ( !s.empty() && s.top()->data<pre[i]){
				temp = s.top();
				s.pop();
			}
			temp->right = node;
			s.push(node);
		}
	}
	return root;
}

void getInorder(Node *root, int (&arr)[10], int *i){
	if (root==NULL){
		return;
	} 
	getInorder(root->left, arr, i);
	arr[*i] = root->data;
	*i++;
	getInorder(root->right, arr, i);
}

void bst_from_tree(Node *root){
	int arr[10], i=0;
	getInorder(root, arr, &i);
}

int main(int argc, char const *argv[])
{
	int pre[] = {10, 5, 1, 7, 40, 50};
	int n = 6;
	// Node *root  =bst_from_pre(pre, n);
	// inorder(root);
	// cout<<endl;

	// Node *root  =bst_from_pre_order_n(pre, n);
	// inorder(root);
	// cout<<endl;

	// Node *root  =bst_from_pre_stack(pre, n);
	// inorder(root);
	// cout<<endl;


	Node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = createNewNode(10);
    root->left = createNewNode(30);
    root->right = createNewNode(15);
    root->left->left = createNewNode(20);
    root->right->right = createNewNode(5);
    bst_from_tree(root);
    // bfs_queue_at_le	vel(root);
	return 0;
}