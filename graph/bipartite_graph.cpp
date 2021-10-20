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
bool dfs_helper(vector<int> v[], int *visited, int color, int node, int parent) {
	visited[node] = color;
	for (auto nbr : v[node]) {
		if (visited[nbr] == 0) {
			bool subproblem = dfs_helper(v, visited, 3 - color, nbr, node);
			if (subproblem == false) {
				return false;
			}
		} else {
			if (parent != nbr && visited[nbr] == color) {
				return false;
			}
		}
	}
	return true;
}
bool dfs(vector<int> v[], int n) {
	//we will have a vistted array where 0->not visited,
	//                                  1->colored 1,
	// 									2->colored_2
	int visited[n] = {0};
	int color = 1;
	return dfs_helper(v, visited, color, 0, -1);
}

int32_t main()
{
	c_p_c();
	int n; cin >> n;
	int M; cin >> M;
	vector<int> v[n];
	while (M--) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << dfs(v, n);
	return 0;
}