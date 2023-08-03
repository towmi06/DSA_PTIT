#include<bits/stdc++.h>
using namespace std;
bool isOperator(string s){
	if(s=="+"||s=="-"||s=="*"||s=="/") return true;
	return false;
}
long long cal(long long a, long long b, string op){
	if(op=="+") return a+b;
	if(op=="-") return a-b;
	if(op=="*") return a*b;
	return a/b;
}
void prefix(string s[], int n){
	stack<long long> st;
	long long a, b; int i;
	for(i=n-1; i>=0; i--){
		if(isOperator(s[i])){
			a=st.top(); st.pop();
			b=st.top(); st.pop();
			st.push(cal(a,b,s[i]));
		}else st.push(stoll(s[i]));
	}
	cout << st.top() << endl;
}
void suffix(string s[], int n){
	stack<long long> st;
	long long a, b; int i;
	for(i=0; i<n; i++){
		if(isOperator(s[i])){
			b=st.top(); st.pop();
			a=st.top(); st.pop();
			st.push(cal(a,b,s[i]));
		}else st.push(stoll(s[i]));
	}
	cout << st.top() << endl;
}
main(){
	int t,n,i; cin >> t;
	while(t--){
		cin >> n;
		string s[1005];
		for(i=0;i<n; i++) cin >> s[i];
		if(isOperator(s[n-1])) suffix(s,n);
		else prefix(s,n);
	}
}

