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
int findindex_of_1st(int *arr, int n, int k) {
	if (n == 0)return -1;
	if (arr[0] == k) {
		return 0;
	}
	int i = findindex_of_1st(arr + 1, n - 1, k);
	if (i == -1) {
		return -1;
	}
	return i + 1;
}
int findindex(int arr[], int i, int n, int k) {

	if (i == n)return -1;
	if (arr[i] == k)return i;
	return findindex(arr, i + 1, n, k);
}

int32_t main()
{
	c_p_c();
	int arr[] = {1, 2, 3, 5, 4, 10, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 12;
	int i = findindex_of_1st(arr, n, key);
	cout << i << endl;
	int j = findindex(arr, 0, n, key);
	cout << j << endl;
	return 0;
}