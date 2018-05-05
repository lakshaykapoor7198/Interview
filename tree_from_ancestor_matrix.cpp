#include <bits/stdc++.h>
using namespace std;
#define N 6

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

Node * constructTree(int mat[N][N]){
	int parent[N];
	int i,j;
	for (i=0;i<N;i++) parent[i] = 0;

	multimap <int, int> m;
	for (i=0;i<N;i++){
		int sum = 0;
		for (j=0;j<N;j++){
			sum+=mat[i][j];
		}
		m.insert(pair <int,int> (sum,i));
	}

	Node *nodes[N];
	Node *root = NULL;
	multimap <int, int > :: iterator it;
	for (it=m.begin();it!=m.end();++it){
		nodes[it->second] = createNewNode(it->second);
		root = nodes[it->second];

		if (it->second!=0){
			for (i=0;i<N;i++){
				if (parent[i]==0 && mat[it->second][i]){
					if (nodes[it->second]->left==NULL){
						nodes[it->second]->left = nodes[i];
					}
					else{
						nodes[it->second]->right = nodes[i];
					}
					parent[i]=1;
				}
			}
		}
	}

	return root;
}


int main(int argc, char const *argv[])
{
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 0 }
    };

    Node *root  = constructTree(mat);
    inorder(root);
	return 0;
}