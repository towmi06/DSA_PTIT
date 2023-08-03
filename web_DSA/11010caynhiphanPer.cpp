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

bool perfect(Node* root, int level){
    queue<Node*> Q;
    Q.push(root);
    int s = 0, f = 0, l = 0;
    while(!Q.empty()){
        s = Q.size();
        f = 0;
        if(s != int(pow(2, l)))
            return false;
        for(int i = 0; i < s; i++){
            Node* t = Q.front();
            Q.pop();
            if(t->left)
                Q.push(t->left);
            if(t->right)
                Q.push(t->right);
        }
        l++;
    }
    return true;
}

void insert(Node* root, int n1, int n2, char c){
    if(root == NULL)
        return;
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
    int t;   cin >> t;
    while(t--){
        int n;  cin >> n;
        Node* root = NULL;
        while(n--){
            int n1, n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(root == NULL){
                root = new Node(n1);
                if(c == 'L') root->left = new Node(n2);
                else if(c == 'R') root->right = new Node(n2);
            }
            else   insert(root, n1, n2, c);
        }
        if(perfect(root, 0)) cout << "YES" << endl;
        else  cout << "NO" << endl;
    }
    return 0;
}
