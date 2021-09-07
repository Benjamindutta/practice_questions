#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
int fact(int n) {
	if (n == 0)return 1;
	return n * fact(n - 1);
}


int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	cout << fact(5);
	return 0;

}