#include<bits/stdc++.h>
using namespace std;

class Matrix{
private:
    int a[2][3];
    int cnt;
public:
    friend istream &operator >> (istream &is, Matrix &A)
    {
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                is >> A.a[i][j];
        return is;
    }
    
    bool operator == (Matrix &A){
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                if(this -> a[i][j] != A.a[i][j])
                    return 0;
        return 1;
    }
    
    void phai(){
        int x, y, z, t;
        x = this -> a[0][1];
        y = this -> a[0][2];
        z = this -> a[1][1];
        t = this -> a[1][2];
        this -> a[0][1] = z;
        this -> a[0][2] = x;
        this -> a[1][1] = t;
        this -> a[1][2] = y;
    }
    
    void trai(){
        int x, y, z, t;
        x = this -> a[0][0];
        y = this -> a[0][1];
        z = this -> a[1][0];
        t = this -> a[1][1];
        this -> a[0][0] = z;
        this -> a[0][1] = x;
        this -> a[1][0] = t;
        this -> a[1][1] = y;
    }
    
    int getCnt(){
        return this -> cnt;
    }
     void updateCnt(int x){
        this -> cnt = x;
    }
};

Matrix S, E, u, tmp;

inline void BFS(){
    queue<Matrix> q;
    q.push(S);
    S.updateCnt(0);
    vector<Matrix> v;
    v.push_back(S);
    while(q.size()){
        u = q.front();
        q.pop();
        tmp = u;
        tmp.trai();
        tmp.updateCnt(u.getCnt() + 1);
        if(tmp == E){
            cout << tmp.getCnt() << endl;
            return;
        }
        q.push(tmp);
        tmp = u;
        tmp.phai();
        tmp.updateCnt(u.getCnt() + 1);
        if(tmp == E){
            cout << tmp.getCnt() << endl;
            return;
        }
        q.push(tmp);
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        cin >> S >> E;
        if(S == E){
            cout << 0 << endl;
            continue;
        }
        BFS();
    }
    return 0;
}