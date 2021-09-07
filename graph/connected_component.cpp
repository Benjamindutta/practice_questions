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
void dfs(vector<int> adj[], int a, bool visited[]) {
	visited[a] = true;

	// cout << a << " ";

	for (auto i : adj[a]) {
		if (visited[i] == false) {
			bfs(adj, i, visited);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

	int v = 9;
	vector<int> adj[v];
	addedge(adj, 0, 1);
	addedge(adj, 3, 1);
	addedge(adj, 2, 1);
	addedge(adj, 3, 2);
	addedge(adj, 3, 4);
	addedge(adj, 4, 5);
	addedge(adj, 6, 7);
	addedge(adj, 7, 8);
	addedge(adj, 8, 6);
	// addedge(adj, 5, 2);
	printgraph(adj, v);
	bool visited[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	int count = 0;
	for (int i = 0; i < v; i++) {
		if (visited[i] == false) {

			dfs(adj, i, visited);
			count++;
		}
	}
	cout << count << endl;


}