#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
void printNto1(int n) {
	if (n == 0)return;
	cout << n << " ";
	printNto1(n - 1);
}


int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	printNto1(5);
	return 0;

}