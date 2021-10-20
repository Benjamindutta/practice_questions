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
class DSU {
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		//initialize to 1 for rank and for parent initialize to -1
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	//find function
	int find(int i) {
		if (parent[i] == -1) {
			return i;
		}
		return parent[i] = find(parent[i]);
	}
	void unionset(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}

	}
};
class Graph {
	vector<vector<int>> edgelist;
	int v;
public:
	Graph(int v) {
		this->v = v;
	}

	void addedge(int w, int x, int y) {
		edgelist.push_back({w, x, y});
	}
	int kruksal() {
		DSU d(v);
		int ans = 0;
		sort(edgelist.begin(), edgelist.end());
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if (d.find(x) != d.find(y)) {
				d.unionset(x, y);
				ans += w;
			}
		}
		return ans;
	}
};

int32_t main()
{
	c_p_c();
	Graph g(5);
	g.addedge(0, 1, 1);
	g.addedge(1, 3, 3);
	g.addedge(3, 2, 4);
	g.addedge(2, 0, 2);
	g.addedge(0, 3, 2);
	g.addedge(1, 2, 2);
	cout << g.kruksal();
	return 0;
}