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
template<typename T>
class Graph {
	map<T, list<T>> l;
public:
	void addedge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs(T src, map<T, bool> &visited, int &count) {
		visited[src] = true;
		for (auto nodes : l[src]) {
			if (visited[nodes] == false) {
				count++;
				dfs(nodes, visited, count);
			}
		}
	}
	int nCr(int n, int r)
	{
		return fact(n) / (fact(r) * fact(n - r));
	}

// Returns factorial of n
	int fact(int n)
	{
		int res = 1;
		for (int i = 2; i <= n; i++)
			res = res * i;
		return res;
	}
	int no_ways_to_moon(int n) {
		map<T, bool> visited;
		for (auto p : l) {
			T nodes = p.first;
			visited[nodes] = false;
		}
		int sum = 0;
		for (auto node : l) {
			if (visited[node] == false) {
				int count = 0;
				dfs(node, visited, count);
				sum += nCr(count, 2);
			}
		}
		int total = nCr(n, 2);
		int ways = total - sum;
		return ways;
	}


};
int32_t main()
{
	c_p_c();
	int n, k; cin >> n >> k;
	Graph<int> g;
	for (int i = 0; i < k; i++) {
		int x, y;
		g.addedge(x, y);
	}
	cout << g.no_ways_to_moon(n);

	return 0;
}