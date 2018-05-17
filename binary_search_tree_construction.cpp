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

void getInorder(Node *root, vector <int> &v){
	if (root==NULL){
		return;
	}
	getInorder(root->left, v);
	v.push_back(root->data);
	getInorder(root->right, v);
}

void convert_to_bst(Node *root, vector <int> v, int &i){
	if (root==NULL){
		return;
	}
	convert_to_bst(root->left, v, i);
	root->data = v[i];
	i++;
	convert_to_bst(root->right, v, i);
}

void bst_from_tree(Node *root){
	vector <int> v;
	getInorder(root, v);
	sort(v.begin(), v.end());
	int i=0;
	convert_to_bst(root,v, i);
}

void sum_of_greater_added(Node *root){
	stack <Node *> s;
	Node *curr  = root;
	int prev=0;
	while (1){
		if (curr){
			s.push(curr);
			curr = curr->right;
		}
		else{
			if (!s.empty()){
				curr = s.top();
				s.pop();
				curr->data+=prev;
				prev=curr->data;
				curr= curr->left;
			}
			else{
				break;
			}
		}
	}
}

Node * array_to_bst(int arr[], int l, int h){
	Node *node = NULL;
	if (l<=h){
		int mid  =(l+h)/2;
		node  =createNewNode(arr[mid]);
		node->left = array_to_bst(arr, l, mid-1);
		node->right = array_to_bst(arr, mid+1, h);
	}
	return node;
}

void showQ(queue <Node *> q){
	queue <Node *> q1 = q;
	while (!q1.empty()){
		cout<<q1.front()->data<<" ";
		q1.pop();
	}
	cout<<"\n";
}


Node * bst_from_bfs(int arr[], int n){
	queue <Node *> q;
	queue <int> minQ, maxQ;
	Node *root = createNewNode(arr[0]), *node, *temp;
	q.push(root);
	minQ.push(INT_MIN);
	maxQ.push(INT_MAX);
	int i=1;
	while (1){
		if (!q.empty() && i<n){
			temp = q.front();
			q.pop();
			int topMin = minQ.front();
			minQ.pop();
			int topMax = maxQ.front();
			maxQ.pop();
			if (arr[i]<temp->data && arr[i]>=topMin){
				node = createNewNode(arr[i]);
				temp->left =node;
				minQ.push(topMin);
				maxQ.push(temp->data-1);
				q.push(node);
				i++;
			}
			if (arr[i]>temp->data && arr[i]<=topMax){
				node = createNewNode(arr[i]);
				temp->right = node;
				minQ.push(temp->data+1);
				maxQ.push(topMax);
				q.push(node);
				i++;
			}
		}
		else{
			break;
		}
	}
	return root;
}

void preorder(Node *node){
	if (node==NULL){
		return;
	}
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}

vector <Node *> all_bst(int start, int end){
	vector <Node *> list;
	if (start>end){
		list.push_back(NULL);
		return list;
	}
	for (int i=start; i<=end; i++){
		vector <Node *> leftSubtree = all_bst(start, i-1);
		vector <Node *> rightSubtree = all_bst(i+1, end);
		for (int j=0; j<leftSubtree.size(); j++){
			Node *left = leftSubtree[j];
			for (int k=0; k<rightSubtree.size(); k++){
				Node *right = rightSubtree[k];
				Node * node = createNewNode(i);
				node->left = left;
				node->right = right;
				list.push_back(node);
			}
		}
	}
	return list;
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


	
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
	// Node *root = NULL;
 //    root = createNewNode(10);
 //    root->left = createNewNode(30);
 //    root->right = createNewNode(15);
 //    root->left->left = createNewNode(20);
 //    root->right->right = createNewNode(5);
 //    bst_from_tree(root);
 //    inorder(root);



	// Node *root = createNewNode(5);
 //    root->left = createNewNode(2);
 //    root->right = createNewNode(13);
 //    sum_of_greater_added(root);
 //    inorder(root);


	// int arr[] = {1,2,3,4,5,6};
	// Node *root =array_to_bst(arr,0, 5);
	// inorder(root);


	// int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
	// Node *root  = bst_from_bfs(arr, 9);
	// inorder(root);

	vector <Node *> v  = all_bst(1,3);
	for (int i=0;i<v.size();i++){
		preorder(v[i]);
		cout<<endl;
	}
	return 0;
}