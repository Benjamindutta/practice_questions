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
	}
	void bfs(T src, T dest) {
		map<T, int> dist;
		map<T, T> parent;
		queue<T> q;
		for (auto nodes : l) {
			T node = nodes.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		parent[src] = src;
		dist[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			// cout << node << " ";
			for (auto ele : l[node]) {
				if (dist[ele] == INT_MAX) {
					q.push(ele);
					dist[ele] = dist[node] + 1;
					parent[ele] = node;
				}
			}
		}
		cout << "dist : " << dist[dest] << endl;
		T temp = dest;
		while (temp != src) {
			cout << temp << "->" << " ";
			temp = parent[temp];
		}
		cout << temp << endl;

	}


};

int32_t main()
{
	c_p_c();
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;
	Graph<int> g;
	for (int i = 0; i <= 36; ++i)
	{
		for (int dice = 1; dice <= 6; ++dice)
		{
			int j = i + dice;
			if (j + board[j] <= 36) {
				g.addedge(i, j + board[j]);
			}
		}
	}
	g.addedge(36, 36);
	g.bfs(0, 36);
	return 0;
}