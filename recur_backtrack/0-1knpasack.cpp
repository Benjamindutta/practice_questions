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
int knap_sack(int n, int cap, int wt[], int price[]) {
	if (n == 0 || cap == 0) {return 0;}
	int inclu, exclu;
	inclu = exclu = 0;
	int ans = 0;
	if (wt[n - 1] <= cap) {
		inclu = price[n - 1] + knap_sack(n - 1, cap - wt[n - 1], wt, price);
	}

	exclu = knap_sack(n - 1, cap, wt, price);
	ans = max(inclu, exclu);
	return ans;
}

int32_t main()
{
	c_p_c();
	int wt[] = {1, 2, 3, 5};
	int price[] = {40, 20, 30, 100};
	int n = 4;
	int C = 7;
	int total = knap_sack(n, C, wt, price);
	cout << total << endl;
	return 0;
}