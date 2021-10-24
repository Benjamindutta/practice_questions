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
int solve(int n, vector<vector<int>> h_value) {
	int dp[n + 1][3];
	memset(dp, 0, sizeof(dp));
	dp[1][0] = h_value[1][0];
	dp[1][1] = h_value[1][1];
	dp[1][2] = h_value[1][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = h_value[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = h_value[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = h_value[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
	}
	return max(max(dp[n][0], dp[n][1]), dp[n][2]);
}
int32_t main()
{
	c_p_c();
	int n;
	vector<vector<int>> h_value(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; i++) {
		cin >> h_value[i][0] >> h_value[i][1] >> h_value[i][2];
	}
	cout << solve(n, h_value) << endl;
	return 0;
}