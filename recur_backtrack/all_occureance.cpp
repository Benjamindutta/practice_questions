#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
// #define int             long long
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
void print_all_occ(int *a, int i, int key, int n) {
	if (i == n) {
		return;
	}
	if (a[i] == key) {
		cout << i << " ";
	}
	print_all_occ(a, i + 1, key, n);
} int allocc(int *a, int i, int j, int key, int *out, int n) {
	if (i == n) {
		return j;
	}
	if (a[i] == key) {
		out[j] = i;
		return allocc(a, i + 1, j + 1, key, out, n);
	}
	return allocc(a, i + 1, j, key, out, n);
}

int32_t main()
{
	c_p_c();
	int arr[] = {1, 2, 3, 5, 4, 10, 11, 10 , 12, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 10;
	print_all_occ(arr, 0, key, n);
	cout << endl;
	int out[1000];
	int count = allocc(arr, 0, 0, key, out, n);
	for (int i = 0; i < count; i++) {
		cout << out[i] << " ";
	}
	cout << endl;
	cout << count << endl;
	return 0;
}