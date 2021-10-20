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
// int binomialC(int n, int k) {
// 	if (n - k < k) {
// 		k = n - k;
// 	}
// 	int ans = 1;
// 	for (int i = 0; i < k; ++i)
// 	{
// 		/* code */
// 		ans *= (n - i);
// 		ans /= (i + 1);
// 	}
// 	return ans;
// }
int catalan_num(int n) {
	int arr[n + 1];

	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n ; i++) {
		arr[i] = 0;
		for (int j = 0; j < i; j++)
		{
			/* code */
			arr[i] += (arr[j - 1] * arr[i - j - 1]);
		}
	}
	return arr[n] ;
}
int32_t main()
{
	c_p_c();
	int n;
	cin >> n;
	if (n == 0 || n == 1) {
		cout << 1 << endl;
	}
	int cat = catalan_num(n);
	cout << cat << endl;
	return 0;
}