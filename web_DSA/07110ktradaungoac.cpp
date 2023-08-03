#include<bits/stdc++.h>
using namespace std;
int check(string str){
	int n = str.length(); stack<char> st;
	for(int i=0;i<n;i++){
		if(str[i]=='(' || str[i] =='[' || str[i] == '{')
		    st.push(str[i]);
		else{
			if(st.empty()) return 0;
			char in = st.top(), out = str[i];
			if(in == '(' && out == ')') st.pop();
			else if(in == '[' && out == ']') st.pop();
			else if(in == '{' && out == '}') st.pop();
			else return 0;
		}
	}
	return 1;
}
int main() {
	int t; cin >> t;
	while(t--) {
		string str; cin >> str;
		if(check(str)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}