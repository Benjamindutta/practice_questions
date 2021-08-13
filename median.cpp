#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	int median = (v[n] + v[n - 1]) / 2;
	cout << median;
	return 0;
}