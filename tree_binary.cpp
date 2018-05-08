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

void printLevel(Node *node,int  level){
	if (node==NULL){
		return;
	}
	if (level==1){
		cout<<node->data<<" ";
	}
	else if (level>1){
		printLevel(node->left,level-1);
		printLevel(node->right, level-1);	
	}
}

void bfs(Node *root){
	int h  =height(root);
	for (int i=1;i<=h;i++){
		printLevel(root, i);
		cout<<endl;
	}
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

void show(stack <Node*> s){
	stack <Node*> s1 = s;
	while(!s1.empty()){
		cout<<s1.top()->data<<" ";
		s1.pop();
	}
	cout<<"\n";
}


void inorder_stack(Node *root){
	Node *curr = root;
	stack <Node*> s;
	while (1){
		if (curr){
			s.push(curr);
			curr=curr->left;
		}
		else{
			if (!s.empty()){
				curr = s.top();
				s.pop();
				cout<<curr->data<<" ";
				curr=curr->right; 
			}
			else{
				break;
			}
		}
	}
}

void preorder_stack(Node *root){
	Node *curr = root;
	stack <Node *> s;
	while (1){
		if (curr){
			cout<<curr->data<<" ";
			s.push(curr);
			curr = curr->left;
		}
		else{
			if (!s.empty()){
				curr = s.top();
				s.pop();
				curr = curr->right;	
			}
			else{
				break;
			}
		}
	}
}

void Morris_Inorder(Node *root){
	Node *curr = root;
	while (curr){
		if (curr->left==NULL){
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else{
			Node *pre = curr->left;
			while (pre->right!=NULL && pre->right!=curr){
				pre = pre->right;
			}
			if (pre->right==NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
}

void Morris_Preorder(Node *root){
	Node *curr = root;
	while (curr){
		if (curr->left==NULL){
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else{
			
			Node *pre = curr->left;
			while (pre->right!=NULL && pre->right!=curr){
				pre = pre->right;
			}
			if (pre->right==NULL){
				pre->right = curr;
				cout<<curr->data<<" ";
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				curr = curr->right;
			}
		}
	}
}



void postorder_reverse_preorder(Node *root){
	stack <Node *> s1,s2;
	Node *curr = root;
	while (1){
		if (curr){
			s1.push(curr);
			s2.push(curr);
			curr = curr->right;
		}
		else{
			if (!s2.empty()){
				curr = s2.top();
				s2.pop();
				curr = curr->left;
			}
			else
				break;
		}
	}
	show(s1);
}


void postorder_one_stack(Node *root){
	stack <Node *> s;
	Node *node, *temp,*curr = root;
	while (1){
		if (curr!=NULL){
			if (curr->right){
				s.push(curr->right);
			}
			s.push(curr);
			curr=curr->left;
		}
		else{
			if (!s.empty()){
				node = s.top();
				s.pop();
				if (s.size()!=0 && node->right!=NULL &&  node->right==s.top()){
					temp = s.top();
					s.pop();
					s.push(node);
					curr = node->right;
				}
				else{
					cout<<node->data<<" ";
					curr=NULL;
				}	
			}
			else{
				break;
			}
		}
	}
}


int search(int arr[], int x, int n){
	for (int i =0;i<n;i++){
		if (arr[i]==x){
			return i;
		}
	}
}

void postorder_from_preorder_and_inorder(int in[], int pre[], int n){
	int root = search(in, pre[0], n);
	if (root!=0)
		postorder_from_preorder_and_inorder(in, pre+1, root);

	if( root!=n-1)
		postorder_from_preorder_and_inorder(in+root+1, pre+root+1, n-root-1);

	cout<<in[root]<<" ";
}

void diagonal_traversal(Node *root){
	stack <Node *> s1;
	stack <Node *> s2;
	s1.push(root);
	Node *curr;
	int flag = 0;
	while (1){
		if (!s1.empty() && flag==0){
			curr = s1.top();
			s1.pop(); 
			while (curr!=NULL){
				cout<<curr->data<<" ";
				if (curr->left!=NULL) s2.push(curr->left);
				if(curr->right!=NULL) curr = curr->right;
				else if (!s1.empty()){
					curr = s1.top();
					s1.pop();
				}
				else{
					break;
				}
			}
			flag = 1;
			cout<<endl;
		}
		else if(!s2.empty() && flag==1){
			curr = s2.top();
			s2.pop(); 
			while (curr!=NULL){
				cout<<curr->data<<" ";
				if (curr->left!=NULL) s1.push(curr->left);
				if(curr->right!=NULL) curr = curr->right;
				else if (!s2.empty()){
					curr = s2.top();
					s2.pop();
				}
				else{
					break;
				}
			}
			flag = 0;
			cout<<endl;
		}
		else{
			break;
		}
	}
}

void leaf_traversal(Node *node){
	if (node==NULL){
		return;
	}
	if (node->left==NULL && node->right==NULL){
		cout<<node->data<<" ";
	}
	leaf_traversal(node->left);
	leaf_traversal(node->right);
}


int minWidth = INT_MAX, maxWidth = INT_MIN;

void getWidth(Node *node, int currentWidth){
	if (node==NULL){
		return;
	}
	if (currentWidth<minWidth){
		minWidth = currentWidth;
	}
	if (currentWidth>maxWidth){
		maxWidth = currentWidth;
	}
	getWidth(node->left, currentWidth-1);
	getWidth(node->right, currentWidth+1);
}

void one_level_traversal(Node *node,int hd, int  level){
	if (node==NULL){
		return;
	}
	if (level==hd){
		cout<<node->data<<" ";
	}
	one_level_traversal(node->left,hd, level-1);
	one_level_traversal(node->right,hd, level+1);
}

void vertical_order(Node *root){
	for (int i=minWidth; i<=maxWidth; i++){
		one_level_traversal(root,i,0);
		cout<<endl;
	}
}

map <int, vector <int> > m;
void vertical_order_hashmap(Node *node, int hd){
	if (node==NULL){
		return;
	}
	m[hd].push_back(node->data);
	vertical_order_hashmap(node->left,hd-1);
	vertical_order_hashmap(node->right,hd+1);
}

void left_boundary_traversal(Node *node){
	if (node->left==NULL && node->right==NULL){
		return;
	}
	if (node==NULL){
		return;
	}
	cout<<node->data<<" ";
	if (node->left){
		left_boundary_traversal(node->left);
	}
	else{
		left_boundary_traversal(node->right);
	}
}

void right_boundary_traversal(Node *node){
	if (node->left==NULL && node->right==NULL){
		return;
	}
	if (node==NULL){
		return;
	}
	
	if (node->left){
		right_boundary_traversal(node->right);
	}
	else{
		right_boundary_traversal(node->left);
	}
	cout<<node->data<<" ";
}


void boundary_traversal(Node *root){
	left_boundary_traversal(root);
	leaf_traversal(root);
	right_boundary_traversal(root->right);
	cout<<endl;
}


Node * tree_from_inorder_and_preorder(int in[],int  pre[],int n){
	int root = search(in, pre[0], n);
	Node *node = createNewNode(pre[0]);
	if (root!=0){
		node->left = tree_from_inorder_and_preorder(in, pre+1, root);
	}
	if (root!=n-1){
		node->right = tree_from_inorder_and_preorder(in+root+1, pre
			+root+1, n-root-1);
	}
	return node;
}

int search1(int in[],int x,int start,int end){
	for (int i=start;i<=end;i++){
		if (in[i]==x){
			return i;
		}
	}
	return -1;
}

int *extract(int in[], int lo[], int start, int end, int n){
	int size = end - start +1;
	int *arr = (int *) malloc(size*sizeof(int));
	int k=0;
	for (int i=0;i<n;i++){
		if (search1(in, lo[i], start, end)!=-1)
			arr[k++] = lo[i];
	}
	return arr;
}

Node *tree_from_inorder_and_levelorder(int in[], int lo[], int n){
	int index  =search1(in, lo[0], 0, n-1);
	Node *node = createNewNode(lo[0]);
	if (index!=0){
		int *lo_left = extract(in, lo,0, index-1 ,n);
		node->left = tree_from_inorder_and_levelorder(in,lo_left,index);
	}
	if (index!=n-1){
		int *lo_right = extract(in, lo,index+1, n-1 ,n);
		node->right = tree_from_inorder_and_levelorder(in+index+1,lo_right,n-index-1);
	}
	return node;
}


Node * tree_special_zero_or_two_child(int pre[], int preN[], int index, int n){
	if (index==n){
		return NULL;
	}
	Node *node = createNewNode(pre[index]);
	if (preN[index]=='n'){
		node->left  =tree_special_zero_or_two_child(pre, preN, index+1, n);
		node->right  =tree_special_zero_or_two_child(pre, preN, index+1, n);
	}
	return node;	
}



void bottom_view(Node *root, map <int, pair <int, int> > &m,int width, int depth){
	if (root==NULL){
		return;
	}
	// cout<<root->data<<" "<<depth<<" "<<m[width].second<<endl;
	if (m.find(width)!=m.end()){
		if (depth>m[width].second){
			m[width]=pair <int, int> (root->data, depth);
		}
	}
	else{
		m[width]=pair <int, int> (root->data, depth);
	}
	bottom_view(root->left,m,width-1, depth+1);
	bottom_view(root->right,m,width+1, depth+1);
}

int main(int argc, char const *argv[])
{
	// Node *root = createNewNode(1);
	// root->left = createNewNode(2);
	// root->right = createNewNode(3);
	// root->left->left = createNewNode(4);
	// root->left->right = createNewNode(5);
	// inorder(root);
	// cout<<endl;
	// preorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// cout<<height(root)<<endl;
	// bfs(root);
	// bfs_queue(root);
	// bfs_queue_at_level(root);
	// inorder_stack(root);
	// preorder_stack(root);
	// Morris_Inorder(root);
	// Morris_Preorder(root);
	// postorder_reverse_preorder(root);
	// postorder_one_stack(root);
	// int in[] = {4,2,5,1,3};
	// int pre[] = {1,2,4,5,3};
	// int n =5;
	// postorder_from_preorder_and_inorder(in, pre, n);
	// diagonal_traversal(root);
	// leaf_traversal(root);
	// getWidth(root, 0);
	// vertical_order(root);
	// vertical_order_hashmap(root, 0);
	// map < int, vector <int> > :: iterator it;
	// for (it=m.begin(); it!=m.end(); ++it){
	// 	vector <int> v = it->second;
	// 	for (int i=0;i<v.size();i++){
	// 		cout<<v[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// boundary_traversal(root);

	//Tree construction:
	// int in[] = {4,2,5,1,3};
	// int pre[] = {1,2,4,5,3};
	// int lo[] = {1,2,3,4,5};
	// int preN[] = {'n','n','l','l','l'};
	// int n =5;
	// Node *root = tree_from_inorder_and_preorder(in, pre, n);
	// inorder_stack(root);
	// Node *root = tree_from_inorder_and_levelorder(in, lo, n);
	// inorder_stack(root);
	// Node *root  =tree_special_zero_or_two_child(pre, preN,0, n);
	// inorder_stack(root);



	Node *root = createNewNode(20);
    root->left = createNewNode(8);
    root->right = createNewNode(22);
    root->left->left = createNewNode(5);
    root->left->right = createNewNode(3);
    root->right->left = createNewNode(4);
    root->right->right = createNewNode(25);
    root->left->right->left = createNewNode(10);
    root->left->right->right = createNewNode(14);
    getWidth(root, 0);
    map <int, pair <int, int> > m;
    bottom_view(root, m, 0, 0);
    pair <int, int> p;	
	map <int, pair <int, int> > :: iterator it;
	for (it=m.begin();it!=m.end();++it){
		p  = it->second;
		cout<<p.first<<" ";
	}
	cout<<endl;
	return 0;
}