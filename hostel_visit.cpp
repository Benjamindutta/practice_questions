#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int n, k; cin >> n >> k;
	long long x, y, q;;
	priority_queue<long long> pq;
	for (int i = 0; i < n; i++) {
		cin >> q;
		if (q == 1) {
			cin >> x >> y;
			pq.push(x * x + y * y);
			if (pq.size() > k) {
				pq.pop();
			}

		} else {
			cout << pq.top() << endl;
		}

	}
	return 0;
}