#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int no_of_set_bit(int n) {
	int ans = 0;
	while (n > 0) {
		if (n & 1) {
			ans++;
		}
		n = n >> 1;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int q; cin >> q;

	while (q--) {
		int sum = 0;
		int a, b; cin >> a >> b;
		for (int i = a; i <= b; i++) {
			sum += no_of_set_bit(i);
		}
		cout << sum << endl;
	}

}