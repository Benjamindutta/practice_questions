#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void dfs(vector<int> graph[], int node, vector<int> &ordering, bool *visited) {
	visited[node] = true;
	for (auto nbr : graph[node]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, ordering, visited);
		}
	}
	ordering.push_back(node);
}
void dfs2(vector<int> graph[], int i, bool *visited) {
	visited[i] = true;
	cout << i << ",";
	for (auto ele : graph[i]) {
		if (!visited[ele]) {
			dfs2(graph, ele, visited);
		}
	}
}

int32_t main()
{
	c_p_c();
	int N; cin >> N;
	vector<int> graph[N];
	vector<int> reverse_graph[N];
	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		reverse_graph[y].push_back(x);//reverseing the graph
	}
	bool visited[N];
	memset(visited, 0, N);
	vector<int> ordering;
	//step 1-DFS
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(graph, i, ordering, visited);
		}
	}
	//reversing the graph is already done in the input section
	memset(visited, 0, N);
	char componen = 'A';
	for (int i = ordering.size() - 1; i >= 0; i--) {
		if (!visited[ordering[i]]) {
			cout << componen << "-->";
			dfs2(reverse_graph, ordering[i], visited);
			cout << endl;
			componen++;
		}
	}

	return 0;
}