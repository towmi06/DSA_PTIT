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

bool isSameTree(Node* p, Node* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void insert(Node* root, int n1, int n2, char c){
    if(root == NULL)return;
    if(root->data == n1){
        if(c == 'L')root->left = new Node(n2);
        else  root->right = new Node(n2);
    }
    else{
        insert(root->left, n1, n2, c);
        insert(root->right, n1, n2, c);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node* root1 = NULL;
        while(n--){
            int n1, n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(root1 == NULL){
                root1 = new Node(n1);
                if(c == 'L')
                    root1->left = new Node(n2);
                else if(c == 'R')
                    root1->right = new Node(n2);
            }
            else{
                insert(root1, n1, n2, c);
            }
        }

        cin >> n;
        Node* root2 = NULL;
        while(n--){
            int n1, n2;
            char c;
            cin >> n1 >> n2 >> c;
            if(root2 == NULL){
                root2 = new Node(n1);
                if(c == 'L')
                    root2->left = new Node(n2);
                else if(c == 'R')
                    root2->right = new Node(n2);
            }
            else{
                insert(root2, n1, n2, c);
            }
        }

        if(isSameTree(root1, root2))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
