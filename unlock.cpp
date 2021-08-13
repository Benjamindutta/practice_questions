#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	vector<pair<int, int>> v;

	int n, k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	int i = 0, j = 0;
	while (i != k) {
		if (a[j] >= a[v[n - j - 1].second]) {
			j++;
		} else {
			swap(a[j], a[v[n - j - 1].second]);
			j++;
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}