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

int mat[N][N];

void ancestorMatrix(Node *root){
	stack <Node *> s;
	int i,j,x1,x2;
	Node *curr = root;
	Node *node = NULL;
	while (1){
		if (curr){
			if (curr->right){
				s.push(curr->right);
			}
			s.push(curr);
			curr =curr->left;
		}
		else{
			if (!s.empty()){
				node  = s.top();
				s.pop();
				if (!s.empty() && node->right!=NULL && node->right==s.top()){
					curr = s.top();
					s.pop();
					s.push(node);
				}
				else{
					int x = node->data;
					if (node->left)  x1=node->left->data;
					else x1=-1;
					if (node->right)  x2=node->right->data;
					else x2=-1;
					for (i=0;i<N;i++){
						if (i==x1){
							mat[x][i]=1;
							for (j=0;j<N;j++){
								if (mat[i][j]==1){
									mat[x][j]=1;
								}
							}
						}
						if (i==x2){
							mat[x][i]=1;
							for (j=0;j<N;j++){
								if (mat[i][j]==1){
									mat[x][j]=1;
								}
							}
						}
					}
				}
			}
			else{
				break;
			}
		}
	}
	for(i=0;i<N;i++){
		for (j=0;j<N;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	Node *root        = createNewNode(5);
    root->left        = createNewNode(1);
    root->right       = createNewNode(2);
    root->left->left  = createNewNode(0);
    root->left->right = createNewNode(4);
    root->right->left = createNewNode(3);
    ancestorMatrix(root);
	return 0;
}