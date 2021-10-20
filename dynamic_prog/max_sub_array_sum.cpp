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
int max_subarray_sum(int arr[], int n, int dp[]) {
	dp[0] = arr[0] > 0 ? arr[0] : 0;
	int max_so_far = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] < 0) {
			dp[i] = 0;
		}
		max_so_far = max(dp[i], max_so_far);
	}
	return max_so_far;
}

int32_t main()
{
	c_p_c();
	int arr[] = { -3, 4, 5, 8, -4, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	int dp[100] = {0};
	cout << max_subarray_sum(arr, n, dp) << endl;
	return 0;
}