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
int binary_s(int arr[], int l, int r, int x) {
	if (l > r)return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == x)return mid;
	else if (arr[mid] < x) {
		return binary_s(arr, mid + 1, r, x);
	} else {
		return binary_s(arr, l, mid - 1, x);
	}
}

int32_t main()
{
	c_p_c();
	int arr[] {1, 3, 4, 7, 9};
	int i = binary_s(arr, 0, 4, 10);
	cout << i << endl;
	return 0;
}