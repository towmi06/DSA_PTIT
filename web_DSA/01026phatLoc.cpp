#include <bits/stdc++.h>
using namespace std;
void khoitao(int arr[], int n) {
	for(int i = 1; i <= n; i++) {
		arr[i] = 0;
	}
}
bool check(int arr[], int n) {
	for(int i = 1; i <= n; i++) {
		if(arr[i] == 0) {
			return true;
		}
	}
	return false;
}
bool dieukien(int arr[], int n) {
	if(arr[1] != 1 || arr[n] != 0 || n < 6) return false;
	else {
		for(int i = 1; i < n; i++) {
			if(arr[i] == 1 && arr[i] == arr[i + 1]) return false;
		}
		for(int i = 1; i < n - 2; i++) {
			if(arr[i] == 0 && arr[i+1] == 0 && arr[i+2] == 0 && arr[i+3] == 0) return false;
		}
		return true;
	}
}
void hienthi(int arr[], int n) {
	for(int i = 1; i <= n; i++) {
		if(arr[i] == 0) cout << 6;
		else cout << 8;
	};
	cout << endl;
	
}
void sinh(int arr[], int n) {
	int i = n;
	while(i >= 0 && arr[i] == 1) {
		arr[i] = 0; --i;
	}
	arr[i] = 1;
}
int main() {
	int n; cin >> n;
	int arr[n + 1];
	khoitao(arr, n);
	if(dieukien(arr, n)) hienthi(arr, n);
	while(check(arr, n)) {
		sinh(arr, n);
		if(dieukien(arr, n)) hienthi(arr, n);
	}
}

