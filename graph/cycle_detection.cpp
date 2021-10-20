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
	void bfs(T src) {
		map<T, int> dist;
		queue<T> q;
		for (auto nodes : l) {
			T node = nodes.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto ele : l[node]) {
				if (dist[ele] == INT_MAX) {
					q.push(ele);
					dist[ele] = dist[node] + 1;
				}
			}
		}
		for (auto node : dist) {
			cout << node.first << " dist " << node.second << endl;
		}
	}
	bool cycledetection_helper(int src, &visited, int parent) {
		visited[src] = true;
		for (auto nodes : l[src]) {
			if (!visited[nodes]) {
				bool cycle_get = cycledetection_helper(nodes, visited, src);
				if (cycle_get) {
					return true;
				}
			} else {
				if (nodes != parent) {
					return true;
				}
			}
		}
		return false;
	}
	bool cycle_detection() {
		bool *visited = new bool[l.size()];
		for (int i = 0; i < l.size(); ++i)
		{
			/* code */
			visited[i] = false;
		}
		return cycledetection_helper(0, visited, -1)
	}


};

int32_t main()
{
	c_p_c();
	return 0;
}