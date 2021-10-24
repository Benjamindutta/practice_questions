#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
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
// int N = 100005;
vector<int> graph[100005];
void addedge(int x, int y) {
	graph[x].push_back(y);
	graph[y].push_back(x);
}

void bfs(int src, int n, int &ans) {
	vector<int> dist(n + 1, INT_MAX);
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto node : graph[cur]) {
			if (dist[node] == INT_MAX) {
				q.push(node);
				dist[node] = dist[cur] + 1;
			} else if (dist[node] >= dist[cur]) {
				ans = min(ans, dist[node] + dist[cur] + 1);
			}
		}
	}

}
int32_t main()
{
	c_p_c();
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		addedge(x, y);
	}
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		bfs(i, n, ans);
	}
	if (ans != n + 1) {
		cout << "shortest cycle " << ans << endl;
	} else {
		cout << "no cycle" << endl;
	}
	return 0;
}