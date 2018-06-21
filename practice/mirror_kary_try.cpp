#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector <Node *> v;
};

Node * createNewNode(int data){
	Node *node= (Node *) malloc(sizeof(Node));
	node->data=data;
	return node;
}

void insert(Node *node, int src, int dest){
	if(node->data==src){
		Node *child = createNewNode(dest);
		node->v.push_back(child);
	}
	for (int i=0;i<node->v.size();i++){
		insert(node->v[i], src, dest);
	}
}

void printVector(vector <Node *> v){
	for (int i=0;i<v.size();i++){
		cout<<v[i]->data<<" ";
	}
	cout<<endl;
}

bool checkForMirror(Node *root1, Node *root2){
	vector <Node *> v1=root1->v;
	vector <Node *> v2=root2->v;
	// cout<<root1->data<<" "<<root2->data<<endl;
	// printVector(v1);
	// printVector(v2);
	if (v1.size()!=v2.size()){
		return false;
	}
	for (int i=0;i<v1.size();i++){
		if (v1[i]->data!=v2[v2.size()-1-i]->data){
			return false;
		}
	}
	for (int i=0;i<v1.size();i++){
		if (checkForMirror(v1[i],v2[v2.size()-1-i])==false){
			return false;
		}
	}
	return true;
}

void clearEverything(Node *root){
	for (int i=0;i<root->v.size();i++){
		clearEverything(root->v[i]);
	}
	free(root);
}

int main() {
	int t,n,e,src, dest;
	cin>>t;
	while (t--){
	    cin>>n>>e;
	    Node *root1 = createNewNode(0);
	    Node *root2 = createNewNode(0);

	    for (int i=0;i<e;i++){
	        cin>>src>>dest;
	        insert(root1, src-1, dest-1);
	    }
	    for (int i=0;i<e;i++){
	        cin>>src>>dest;
	        insert(root2, src-1, dest-1);
	    }
	    cout<<checkForMirror(root1, root2)<<endl;
	    clearEverything(root1);
	    clearEverything(root2);
	}
	return 0;
}