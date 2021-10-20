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
float find_sq_root(int n, int p) {
	int s = 0;
	int e = n;
	float ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid * mid == n) {
			return mid;
		}
		if (mid * mid < n) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	float inc = 0.1;
	for (int i = 1; i <= p ; ++i)
	{
		while (ans * ans <= n) {
			ans += inc;
		}
		ans = ans - inc;
		inc = inc * 0.1;
	}
	return ans;
}

int32_t main()
{
	c_p_c();
	int n; cin >> n;
	int p; cin >> p;
	cout << find_sq_root(n, p) << endl;
	return 0;
}