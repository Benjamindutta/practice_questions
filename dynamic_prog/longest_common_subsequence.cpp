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
int lcs(string s1, string s2, int i, int j) {
	if (i == s1.length() || j == s2.length()) {
		return 0;
	}
	if (s1[i] == s2[j]) {
		return 1 + lcs(s1, s2, i + 1, j + 1);
	}
	int op1 = lcs(s1, s2, i + 1, j);
	int op2 = lcs(s1, s2, i, j + 1);
	return max(op1, op2);
}
int lcs_memo(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
	if (i == s1.length() || j == s2.length()) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + lcs_memo(s1, s2, i + 1, j + 1, dp);
	}
	int op1 = lcs_memo(s1, s2, i + 1, j, dp);
	int op2 = lcs_memo(s1, s2, i, j + 1, dp);
	return dp[i][j] = max(op1, op2);
}



int32_t main()
{
	c_p_c();
	string s1 = "ABCD";
	string s2 = "ABGED";
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1, vector<int>(n2, -1));
	cout << lcs(s1, s2, 0, 0) << endl;
	cout << lcs_memo(s1, s2, 0, 0, dp) << endl;
	return 0;
}