#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
int summ(int n) {
	if (n == 0)return 0;
	return n % 10 + summ(n / 10);
}

int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	cout << summ(15);
	return 0;

}