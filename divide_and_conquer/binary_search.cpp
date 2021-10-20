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
int binary_search_recursive(int in[], int s, int e, int x) {
	if (s > e) {
		return -1;
	}
	int mid = (s + e) / 2;
	if (in[mid] == x) {
		return mid;
	} else if (in[mid] < x) {
		binary_search_recursive(in, mid + 1, e, x);
	} else {
		binary_search_recursive(in, s, mid - 1, x);
	}
}
int binary_search_iterative(int arr[], int n, int x) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == x) {
			return mid;
		} else if (arr[mid] < x) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return -1;
}

int32_t main()
{
	c_p_c();
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> arr[i];
	}
	int x; cin >> x;
	cout << binary_search_recursive(arr, 0, n - 1, x) << endl;
	cout << binary_search_iterative(arr, n, x) << endl;
	return 0;
}