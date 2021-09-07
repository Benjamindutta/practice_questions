#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
int fibb(int n) {
	if (n == 0 || n == 1)return n;

	return fibb(n - 1) + fibb(n - 2);
}


int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	cout << fibb(5);
	return 0;

}