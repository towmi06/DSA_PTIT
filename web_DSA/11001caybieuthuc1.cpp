#include<bits/stdc++.h>
using namespace std;
typedef Node* binTree;

struct Node{
    char c;
    Node *left, *right;
};

inline binTree createNode(char c){
    binTree res = new Node;
    res -> c = c;
    res -> left = res -> right = NULL;
    return res;
}

inline void order(binTree a){
    if(a != NULL) {
        order(a -> left);
        cout << a -> c;
        order(a -> right);
    }
}

int main(){
    int t = 1;  cin >> t;
    string s;
    while(t--) {
        cin >> s;
        stack<binTree> st;
        for(char &i : s){
            if(i == '+' or i == '-' or i == '*' or i == '/'){
                binTree tmp = createNode(i);
                tmp -> right = st.top(); st.pop();
                tmp -> left = st.top(); st.pop();
                st.push(tmp);
            }else st.push(createNode(i));
        }
        order(st.top());
        cout << endl;
    }
    return 0;
}