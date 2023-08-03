#include <bits/stdc++.h>
using namespace std;
void nhap(int A[], int n){
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
}
void cal_L(int A[],int L[],int n){
    stack<int> S;
    for(int i=0;i<n;i++){
        while(!S.empty()&&A[S.top()]<= A[i]){
            S.pop();
        }
        L[i]=S.empty()?-1:S.top();
        S.push(i);
    }
}
void cal_R(int A[],int R[],int n){
    stack<int> S;
    for(int i=n-1;i>=0;i--) {
        while(!S.empty()&&A[S.top()]<=A[i]){
            S.pop();
        }
        R[i]=S.empty()?-1:S.top();
        S.push(i);
    }
}
int count_pairs(int L[],int R[],int n){
    int cnt=0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++){
            if(R[i]>=j||R[i]==-1){
                if(L[j]<=i||L[j]==-1){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int A[n],L[n],R[n];
    nhap(A,n);
    cal_L(A,L,n);
    cal_R(A,R,n);
    cout<<count_pairs(L,R,n);
    return 0;
}