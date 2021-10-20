#include<bits/stdc++.h>
#define ll long long
using namespace std;
int count_setbit(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int main() {

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << count_setbit(n) << endl;
	}
	return 0;
}