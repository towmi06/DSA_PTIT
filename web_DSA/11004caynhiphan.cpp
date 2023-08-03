#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void levelOrder(Node* root){
    queue <Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* nd = Q.front();
        Q.pop();
        cout << nd->data << ' ';
        if(nd->left != NULL)
            Q.push(nd->left);
        if(nd->right != NULL)
            Q.push(nd->right);
    }
}

void insert(Node* root, int n1, int n2, char c){
    if(root == NULL) return;
    if(root->data == n1){
        if(c == 'L')
            root->left = new Node(n2);
        else
            root->right = new Node(n2);
    }
    else{ 
        insert(root->left, n1, n2, c);
        insert(root->right, n1, n2, c);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node* root = NULL;
        while(n--){
            int n1, n2;// dinh cha dinh con
            char c;// trai phai
            cin >> n1 >> n2 >> c;
            if(root == NULL){
                root = new Node(n1);
                if(c == 'L')
                    root->left = new Node(n2);
                else if(c == 'R')
                    root->right = new Node(n2);
            }
            else{
                insert(root, n1, n2, c);
            }
        }
        levelOrder(root);
        cout << endl;
    }
    return 0;
}
