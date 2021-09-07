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

//connected components counting
void bfs(vector<int> adj[], int a, bool visited[]) {
	queue<int> q;
	q.push(a);
	visited[a] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (auto i : adj[node]) {
			if (visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
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
	// counting connected componenets

	bfs(adj, 0, visited);



}