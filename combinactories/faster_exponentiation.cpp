#include<bits/stdc++.h>
using namespace std;
int faster_expo(int i, int n) {
	if (n == 0)return 1;
	if (n & 1) {
		return i * faster_expo(i, n / 2) * faster_expo(i, n / 2);
	} else {
		return faster_expo(i, n / 2) * faster_expo(i, n / 2);
	}
}

int main() {
	int i; cin >> i;
	int n; cin >> n;
	cout << faster_expo(i, n);
}