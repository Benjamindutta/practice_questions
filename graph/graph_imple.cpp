#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// addedge(vector<int> adj,int u,int v)
void addedge(vector<int> ad[], int u, int v) {
	ad[u].push_back(v);
	ad[v].push_back(u);
}
void printgraph(vector<int> v[], int vi) {
	for (int i = 0; i < vi; i++) {
		cout << i << " ->";
		for (int j : v[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}
int main() {
// #ifndef ONLINE_JUDGE

// 	freopen("input.txt", "r", stdin);

// 	freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE

	int v = 4;
	vector<int> adj[v];
	addedge(adj, 0, 1);
	addedge(adj, 3, 1);
	addedge(adj, 2, 1);
	addedge(adj, 3, 2);
	printgraph(adj, v);

}