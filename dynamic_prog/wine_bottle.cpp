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
int wine_problem(int i, int j, int wine[], int y, int dp[][100]) {
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != 0) {
		return dp[i][j];
	}
	int op1 = wine[i] * y + wine_problem(i + 1, j, wine, y + 1, dp);
	int op2 = wine[j] * y + wine_problem(i, j - 1, wine, y + 1, dp);
	int ans = max(op1, op2);
	return dp[i][j] = ans;

}

int32_t main()
{
	c_p_c();
	int wine[] = {2, 3, 5, 1, 4};
	int y = 1;
	int n = sizeof(wine) / sizeof(wine[0]);
	int dp[100][100] = {0};
	int maxprofit = wine_problem(0, n - 1, wine, y, dp);
	cout << maxprofit << endl;

	return 0;
}