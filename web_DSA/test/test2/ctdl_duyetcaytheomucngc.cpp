#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void makeNode(node *root, int n1, int n2, char c) {
    switch (c) {
        case 'L':
            root->left = new node(n2);
            break;
        case 'R':
            root->right = new node(n2);
            break;
    }
}

void Insert(node *root, int n1, int n2, char c) {
    if (root == NULL)
       return;
    if (root->data == n1)
       makeNode(root, n1, n2, c);
    else {
        Insert(root->left, n1, n2, c);
        Insert(root->right, n1, n2, c);
    }
}

void level(node *root) {
    queue<node*> q;
    stack<int> st;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        st.push(current->data);
        if (current->right != NULL)
            q.push(current->right);
        if (current->left != NULL)
            q.push(current->left);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

void testcase() {
    int n; cin >> n;
    node *root = NULL;
    while (n--) {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if (root == NULL) {
            root = new node(n1);
        }
        Insert(root, n1, n2, c);
    }
    level(root);
    cout << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
