#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
void insert(Node* &root,int x){
	if(root==NULL){
		root =new Node(x); return;
	}
	if(root->data >x)	insert(root->left,x);
	if(root->data <x)	insert(root->right,x);
}
void levelOrder(Node* root) {
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *nd = Q.front(); Q.pop();
        cout << nd->data << " ";
		if (nd->right != NULL) Q.push(nd->right);
        if (nd->left != NULL) Q.push(nd->left);
        
    }
}
void postOrder(Node *root){
	if(root==NULL)	return;
	if(root->left)	postOrder(root->left);
	if(root->right)	postOrder(root->right);
	cout <<root->data<<" ";
}
main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];Node *root=NULL;
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++){
			insert(root,a[i]);
		}
	//	postOrder(root);
		levelOrder(root);
		cout<<endl;
	}
}