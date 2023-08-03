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
void levelOrder(Node* root){
    queue<Node* > Q;
    Q.push(root);
    while(!Q.empty()){
        Node *nd=Q.front();Q.pop();
        cout<<nd->data<<" ";
        if(nd->left!=NULL) Q.push(nd->left);
        if(nd->right!=NULL) Q.push(nd->right);
    }
}
void truoc(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        truoc(root->left);
        truoc(root->right);
    }
}
void giua(Node *root){
    if(root!=NULL){
        giua(root->left);
        cout<<root->data<<" ";
        giua(root->right);
    }
}
void sau(Node *root){
    if(root!=NULL){
        sau(root->left);
        sau(root->right);
        cout<<root->data<<" ";
    }
}
void insert(Node*root,int n1,int n2,char c){
    if(root==NULL) return;
    if(root->data==n1){
        if(c=='L') root->left=new Node(n2);
        else root->right=new Node(n2);
    }
    else{
        insert(root->left,n1,n2,c);
        insert(root->right,n1,n2,c);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outtput.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        Node *root=NULL;
        while(n--){
            int n1,n2;char c;
            cin>>n1>>n2>>c;
            if(root==NULL){
                root=new Node(n1);
                if(c=='L') root->left=new Node(n2);
                else root->right=new Node(n2);
            }
            else insert(root,n1,n2,c);
        }
        levelOrder(root);
        cout<<endl;
        truoc(root);
        cout<<endl;
        giua(root);cout<<endl;
        sau(root);cout<<endl;
    }
}