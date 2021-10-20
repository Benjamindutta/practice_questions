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
public:
	map<T, list<T>> l;
	void addedge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << endl;
		visited[src] = true;
		//visit all the node of the source
		for (auto node : l[src]) {
			if (!visited[node]) {
				dfs_helper(node, visited);
			}
		}
		return;
	}
	void dfs(T src) {
		map<T, bool> visited;
		for (auto node : l) {
			visited[node.first] = false;
		}
		dfs_helper(src, visited);
	}
};

int32_t main()
{
	c_p_c();
	Graph<int> g;
	g.addedge(0, 1);
	g.addedge(0, 3);
	g.addedge(3, 2);
	g.addedge(0, 2);
	g.addedge(3, 4);
	g.addedge(4, 5);
	// g.addedge(6, 7);
	g.dfs(0);


	return 0;
}