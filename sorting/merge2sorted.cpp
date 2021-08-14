#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			cout << a[i] << " ";
			i++;
		} else {
			cout << b[j] << " ";
			j++;
		}
	}
	while (i < n) {
		cout << a[i] << " ";
		i++;
	}
	while (j < m) {
		cout << b[j] << " ";
		j++;
	}
	return 0;
}