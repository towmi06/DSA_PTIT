#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int x){
        data = x;
        left= right = NULL;
    }
};
 void insert(node* &root , int x){
    if(root == NULL){
        root = new node(x); return;
    }
    if(root -> data > x) insert (root -> left, x);
    if(root -> data < x) insert (root  -> right, x);
 }
void preOrder(node *root){
    if(root != NULL)  {
        cout << root -> data<< " ";
        preOrder(root -> left );
        preOrder(root -> right);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n]; node *root = NULL;
        for(int i = 0; i< n; i++) cin >> a[i];
        for(int i =0; i< n; i++) insert(root, a[i]);
    preOrder(root);
    cout << endl;
    }
}