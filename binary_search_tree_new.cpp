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

bool isBSTUtil(Node *root, int min, int max){
	if (root==NULL){
		return true;
	}
	if (root->data<min || root->data>max){
		return false;
	}
	if (isBSTUtil(root->left, min, root->data-1) &&isBSTUtil(root->right, root->data+1, max)){
		return true;
	}
	return false;
}

bool isBSTUtil_Pointers(Node *root, Node *l, Node *r){
	if (root==NULL){
		return true;
	}
	if (l && root->data<l->data){
		return false;
	}
	if (r && root->data>r->data){
		return false;
	}
	if (isBSTUtil_Pointers(root->left, l, root) && isBSTUtil_Pointers(root->right, root, r)){
		return true;
	}
	return false;
}

bool inorder_stack(Node *root){
	stack <Node *> s;
	Node *curr = root, *temp;
	int prev = INT_MIN;
	while (1){
		if (curr){
			s.push(curr);
			curr = curr->left;
		}
		else{
			if (!s.empty()){
				temp = s.top();
				s.pop();
				if (temp->data < prev){
					return false;
				}
				else{
					prev = temp->data;
				}
				// cout<<temp->data<<" ";
				curr = temp->right;
			}
			else{
				break;
			}
		}
	}
	// cout<<endl;
	return true;
}


Node * kth_smallest(Node *root, int k){
	stack <Node *> s;
	Node *curr = root, *temp;
	int i=0;
	while (1){
		if (curr){
			s.push(curr);
			curr = curr->left;
		}
		else{
			if (!s.empty()){
				temp = s.top();
				s.pop();
				i++;
				if (i==k){
					return temp;
				}
				curr = temp->right;
			}
			else{
				break;
			}
		}
	}
	return NULL;
	// cout<<endl;
}


bool isBST(Node *root){
	// return isBSTUtil(root, INT_MIN, INT_MAX);
	// return isBSTUtil_Pointers(root, NULL, NULL);
	return inorder_stack(root);
}

bool is_internal_node_has_one_child(int pre[],int i, int n){
	if (i>=n) return true;
	if ((pre[i+1]<pre[0] && pre[n-1]<pre[0]) || (pre[i+1]>pre[0] && pre[n-1]>pre[0])){
		if (is_internal_node_has_one_child(pre, i+1, n)){
			return true;
		}
	}

	return false;
}

void show(stack <Node *> s){
	stack <Node *> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()->data<<" ";
		s1.pop();
	}
	cout<<"\n";
}


void kth_largest(Node *root, int k){
	Node *curr = root;
	stack <Node *> s;
	int i=0;
	while(1){
		if (curr){
			s.push(curr);
			curr = curr->right;
		}
		else{
			if (!s.empty()){
				curr = s.top();
				s.pop();
				i++;
				if (i==k){
					cout<<curr->data<<endl;
					return;
				}
				curr = curr->left;
			}
			else{
				break;
			}
		}
	}
}

void kth_smallest_Morris(Node *root, int k){
	Node *curr = root;
	int i = 0;
	while(curr){
		if (curr->left==NULL){
			i++;
			if (i==k){
				cout<<curr->data<<" ";	
			}
			curr=curr->right;
		}
		else{
			Node *pre = curr->left;
			while (pre->right!=NULL && pre->right!=curr){
				pre= pre->right;
			}
			if (pre->right==NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				i++;
				if (i==k){
					cout<<curr->data<<" ";	
				}
				curr=curr->right;
			}
		}
	}
}

void subseq_check_util(Node *root , int seq[], int *index){
	if (root==NULL){
		return;
	}
	subseq_check_util(root->left, seq, index);
	if (root->data ==seq[*index]){
		*index = *index +1;
	}
	subseq_check_util(root->right, seq, index);
}

bool subseq_check(Node *root, int seq[], int n){
	int index = 0;
	subseq_check_util(root, seq, &index);
	return (index==n);
}

void largest_less_or_equal_N(Node *root, int N, int *prev){
	if (root ==NULL){
		return;
	}
	if (root->data==N){
		*prev = root->data;
		return;
	}
	
	else if (root->data<N){
		if (root->data>*prev){
			*prev = root->data;
			largest_less_or_equal_N(root->right,N, prev);
		}
	}
	else{
		largest_less_or_equal_N(root->left, N, prev);
	}
}

int main(int argc, char const *argv[])
{
	// Node *root 		  = createNewNode(4);
 //    root->left        = createNewNode(2);
 //    root->right       = createNewNode(5);
 //    root->left->left  = createNewNode(1);
 //    root->left->right = createNewNode(3);
    // cout<<isBST(root)<<endl; 
    // cout<<kth_smallest(root, 6)->data<<endl;
    // int pre[] = {20, 10, 11, 13, 12};
    // int n = 5;
    // cout<<is_internal_node_has_one_child(pre,0, n); new_line;
    // kth_largest(root, 1);
    // kth_smallest_Morris(root, 3);
	// Node *root  = NULL;
 //    root = insert(root, 8);
 //    root = insert(root, 10);
 //    root = insert(root, 3);
 //    root = insert(root, 6);
 //    root = insert(root, 1);
 //    root = insert(root, 4);
 //    root = insert(root, 7);
 //    root = insert(root, 14);
 //    root = insert(root, 13);
 //    int seq[] = {4, 6, 8, 14};
 //    int n = sizeof(seq)/sizeof(seq[0]);
	// cout<<subseq_check(root, seq, n)<<endl;


	Node* root = insert(NULL, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);
    int prev =INT_MIN;
    largest_less_or_equal_N(root,4, &prev);
    cout<<prev<<endl;
	return 0;
}