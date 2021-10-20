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
class Graph {
public:
	unordered_map<string, list<pair<string, int>>> l;

	void addedge(string city, string dest, bool isbidir, int dist) {
		l[city].push_back(make_pair(dest, dist));
		if (isbidir) {
			l[dest].push_back(make_pair(city, dist));
		}
	}
	void printedge2() {
		for (auto nbrs : l) {
			cout << nbrs.first << " -> ";
			for (auto nbr : nbrs.second) {
				string dest1 = nbr.first;
				int dist2 = nbr.second;
				cout << "(" << dest1 << "," << dist2 << ")" << " ";
			}
			cout << endl;
		}
	}
};

int32_t main()
{
	c_p_c();
	Graph g;
	g.addedge("A", "B", true, 2);
	g.addedge("A", "C", true, 2);
	g.addedge("B", "C", true, 2);
	g.addedge("A", "D", true, 2);
	g.addedge("D", "B", true, 2);
	g.addedge("D", "C", true, 2);
	g.printedge2();
	return 0;
}