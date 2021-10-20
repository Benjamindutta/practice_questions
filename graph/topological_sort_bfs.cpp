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
	int v;
	list<T> *g;
public:
	Graph(int v) {
		this->v = v;
		g = new list<T>[v];
	}
	void addedge(T x, T y) {
		g[x].push_back(y);
	}
	void topological() {
		queue<T> q;
		// q.push_back(src);
		int indegree[v] = {0};
		for (int i = 0; i < v; ++i)
		{
			for (auto ele : g[i]) {
				indegree[ele]++;
			}
		}
		for (int i = 0; i < v; ++i) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : g[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
		cout << endl;
	}
};

int32_t main()
{
	c_p_c();
	int n, m; cin >> n >> m;
	Graph<int> g(n);
	while (m--) {
		int x, y; cin >> x >> y;
		g.addedge(x, y);
	}
	g.topological();
	return 0;
}