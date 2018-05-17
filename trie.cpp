#include <bits/stdc++.h>
using namespace std;

struct Node {
	bool isEndOfString;
	Node *children[26];
};

Node * createNewNode(){
	Node * node = (Node *) malloc(sizeof(Node));
	node->isEndOfString = false;
	for (int i=0;i<26;i++){
		node->children[i]=NULL;
	}
	return node;
}

void insert(Node *root,string s){
	Node *curr = root;
	for (int i=0;i<s.length();i++){
		Node *node = createNewNode();
		int key = s[i]-'a';
		if (!curr->children[key]){
			curr->children[key] = node;
			curr=node;
			continue;
		}
		curr=curr->children[key];
	}
	curr->isEndOfString = true;
}

bool search(Node *root, string s){
	Node *curr = root;
	for (int i=0;i<s.length();i++){
		int key = s[i]-'a';
		if (!curr->children[key]){
			return false;
		}
		curr=curr->children[key];
	}
	return (curr!=NULL && curr->isEndOfString);
}

bool noChild(Node *root){
	for (int i=0;i<26;i++){
		if (root->children[i]){
			// cout<<char(i+int('a'))<<endl;
			return false;
		}
	}
	return true;
}



void printTrie(Node *root){	
	if (root==NULL){
		return;
	}
	for (int i=0;i<26;i++){
		if (root->children[i]){
			cout<<char(i+int('a'))<<" ";	
			printTrie(root->children[i]);
		}
	}
	cout<<"*"<<endl;
}

bool del(Node *node, int i, string s, int len){
	if (node){
		if (i==len){
			if (noChild(node)){
				node->isEndOfString=false;
				return true;
			}
			return false;
		}
		else{
			int key =s[i]- 'a';
			if (del(node->children[key], i+1, s, len)){
				node->children[key]=NULL;
				free(node->children[key]);
				// cout<<i<<"A"<<noChild(node)<<endl;
				return (!node->isEndOfString && noChild(node));
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	Node *root = createNewNode();

	string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // printTrie(root);
    // cout<<search(root,"the")<<endl;
    // cout<<search(root,"there")<<endl;
    cout<<search(root,"any")<<endl;
    del(root, 0, "any",3);
    // printTrie(root);
    cout<<search(root,"any")<<endl;
	return 0;
}