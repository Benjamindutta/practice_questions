#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
bool ispalin(string s, int start, int end) {
	if (start == end)return true;
	else {
		return (s[start] == s[end] && ispalin(s, start + 1, end - 1));
	}
}

int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int n; cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = arr[0];
	for (int i = 1; i < n; i++) {
		res ^= arr[i];
	}
	cout << res << " ";
}