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
// int no_of_ways(int r, int c, int grid[][c]) {
// 	int dp[r][c];
// 	for (int i = 0; i < r; i++) {
// 		for (int j = 0; j < c; j++) {
// 			if (grid[i][j] != -1) {
// 				if (i == 0 && j == 0) {
// 					dp[i][j] = 1;
// 				} else if (i == 0) {
// 					dp[i][j] = dp[0][j - 1];
// 				} else if (j == 0) {
// 					dp[i][j] = dp[i - 1][0];
// 				} else {
// 					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
// 				}
// 			} else {
// 				dp[i][j] = 0;
// 			}
// 		}
// 	}
// 	return dp[r - 1][c - 1];
// }
int dp[1001][1001];

int32_t main()
{
	c_p_c();
	int m, n, p; cin >> m >> n >> p;
	int grid[m][n];
	for (int i = 0; i < p; i++) {
		int x, y; cin >> x >> y;
		grid[x - 1][y - 1] = -1;
	}
	int r = m;
	int c = n;
	// int dp[r][c];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] != -1) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
				} else if (i == 0) {
					dp[i][j] = dp[0][j - 1];
				} else if (j == 0) {
					dp[i][j] = dp[i - 1][0];
				} else {
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}
	// for (int i = 0; i < 0; i++) {
	// 	for (int j = 0; j < c; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << no_of_ways(m, n, grid) << endl;
	cout << dp[r - 1][c - 1] << endl;
	return 0;
}