#include<iostream>
using namespace std;
#define ll long long
ll fact(ll n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}

}
ll comb(ll n, ll k) {
	return fact(n) / (fact(n - k) * fact(k));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		cout << comb(n - 1, k - 1) << endl;
	}
	return 0;
}