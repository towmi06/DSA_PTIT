#include <bits/stdc++.h>
using namespace std;
int ok;

void khoitao( int s[], int n) {
	for(int i = 0; i < n; i++) {
		s[i] = i + 1;
	}
}

void sinh( int s[], int n, int k) {
	int i = k - 1;
	while(i >= 0 && s[i] == n - k + i + 1) 	i--;
	if(i == -1) ok = 0;
	else {
		s[i]++;
		for(int j = i + 1; j < k; j++) {
			s[j] = s[j - 1] + 1;
		}
	}	
}

void hienthi(int arr[], map<int, string> mp, int k) {
	for(int i = 0; i < k; i++) {
		cout << mp[arr[i]] << " ";
	}
	cout << endl;
}
int main() {
	int n, k; cin >> n >> k;
	cin.ignore();
	string s;
	getline(cin, s);
	vector<string> v;
	set<string> st;
	map<int, string> mp;
	int count = 0;
	string token;
	stringstream ss(s);
	while(ss >> token) 		st.insert(token);
	for(auto x:st) 	v.push_back(x);
	sort(v.begin(), v.end());
	for(auto x:v) 	mp[++count] = x;
	
	int arr[n];
	khoitao(arr, k);
	ok = 1;
	while(ok) {
			hienthi(arr, mp, k);
		sinh(arr, count, k);
	}	
}
