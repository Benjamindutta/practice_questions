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
//# of ways to reach the nth ladder step
int ladder(int n, int k, int dp[]) {
	//base case
	if (n == 0) {
		return 1;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (n - i >= 0) {
			ans += ladder(n - i, k, dp);
		}
	}
	return dp[n] = ans;
}
//bottom up appraoch
int ladder_bottom_up(int n, int k) {
	int dp[100] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}
//optimized approach
int ladder_optimized(int n, int k) {
	int dp[n + 1] = {0};
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i - k > 0) {
			dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
		}
		dp[i] = 2 * dp[i - 1];
	}
	return dp[n];
}
int32_t main()
{
	c_p_c();
	int n, k; cin >> n >> k;
	cout << ladder_optimized(n, k) << endl;
	return 0;
}