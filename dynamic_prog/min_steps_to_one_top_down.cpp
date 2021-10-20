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

int minsteps(int n, int dp[]) {
	if (n == 1)return 0;
	int op3, op2, op1;
	op3 = op2 = op1 = INT_MAX;
	if (dp[n] != 0) {
		return dp[n];
	}
	if (n % 3 == 0) {
		op3 = minsteps(n / 3, dp);
	}
	if (n % 2 == 0) {
		op2 = minsteps(n / 2, dp);
	}
	op1 = minsteps(n - 1, dp);

	int ans = min(min(op1, op2), op3) + 1;
	return dp[n] = ( ans );
}
int32_t main()
{
	c_p_c();
	int n; cin >> n;
	int dp[100] = {0};
	// memset(dp, 0, n + 1);
	cout << minsteps(n, dp) << endl;
	return 0;
}