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

class Graph {
	list<pair<int, int>> l;
	int v;
public:
	Graph(int v) {
		this->v = v;
	}
	void addedge(int x, int y) {
		l.push_back(make_pair(x, y));
	}
	//find the parent of the node
	int findset(int i, int parent[]) {
		if (parent[i] == -1) {
			return i;
		}
		return findset(parent[i], parent);
	}
	//union operation on disjoint set
	void unionset(int x, int y, int parent[]) {
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);
		if (s1 != s2) {
			parent[s1] = s2;
		}
	}
	bool cycle_detection() {
		int *parent = new int[v + 1];
		for (int i = 0; i <= v; i++) {
			parent[i] = -1;
		}
		for (auto edge : l) {
			int s1 = findset(edge.first, parent);
			int s2 = findset(edge.second, parent);
			if (s1 != s2) {
				unionset(s1, s2, parent);
			} else {
				return true;
			}
		}
		return false;
	}
};
int32_t main()
{
	c_p_c();
	Graph g(4);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(2, 3);
	// g.addedge(3, 0);
	cout << g.cycle_detection();
	return 0;
}