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
	int j = 0, i = 0;
	while (i < n && j < m) {
		if (i > 0 && a[i] == a[i - 1]) {
			i++;
			continue;
		} else if (j > 0 && b[j] == b[j - 1]) {
			i++;
			continue;
		}
		else {
			if (a[i] < b[j]) {cout << a[i] << " "; i++;}
			else if (a[i] > b[j]) {cout << b[j] << " "; j++;}
			else {
				cout << a[i] << " ";
				j++;
				i++;
			}
		}
	}
	while (i < n) {
		if (a[i] == a[i - 1]) {
			i++;
			continue;
		}
		cout << a[i] << " ";
		i++;
	}
	while (j < m) {
		if (b[j] == b[j - 1]) {
			j++;
			continue;
		}
		cout << b[j] << " ";
		j++;
	}
	return 0;
}