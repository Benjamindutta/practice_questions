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

	void addedge(T x, T y) {
		l[x].push_back(y);
	}
	void dfs_helper(T src, map<T, bool> &visited, list<T> &li) {
		visited[src] = true;
		for (auto neigh : l[src]) {
			if (!visited[neigh]) {
				dfs_helper(neigh, visited, li);
			}
		}

		li.push_front(src);
		return;
	}
	void dfs() {
		map<int, bool> visited;
		list<T> li;
		for (auto p : l) {
			visited[p.first] = false;
		}
		for (auto node : l) {
			int cur = node.first;
			if (visited[cur] == false) {
				dfs_helper(cur, visited, li);
			}
		}
		for (auto node : li) {
			cout << node << " ";
		}
		cout << endl;
	}
};

int32_t main()
{
	c_p_c();
	Graph<int> g;
	g.addedge(5, 2);
	g.addedge(5, 0);
	g.addedge(4, 0);
	g.addedge(4, 1);
	g.addedge(2, 3);
	g.addedge(3, 1);
	g.dfs();
	return 0;
}