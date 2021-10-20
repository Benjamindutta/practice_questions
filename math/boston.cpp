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
int sumofdig(int n) {
	int sum = 0;
	while (n > 0) {
		sum += (n % 10);
		n = n / 10;
	}
	return sum;
}
int sumof_factor(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		while (v[i]) {
			sum += (v[i] % 10);
			v[i] = v[i] / 10;
		}
	}
	return sum;
}
vector<int> primes(int n) {
	vector<int> v;
	while (n % 2 == 0) {
		v.pb(2);
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			v.pb(i);
			n = n / i;
		}
	}
	if (n > 2) {
		v.pb(n);
	}
	return v;
}


int32_t main()
{
	c_p_c();
	int n; cin >> n;
	vector<int> vv = primes(n);
	int sum = sumof_factor(vv);
	if (sumofdig(n) == sum) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}