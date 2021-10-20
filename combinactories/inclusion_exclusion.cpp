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

int k;
vector<int> a, b, c;
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(k + 1, vector<int>(k + 1));
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			for (int x = 1; x <= k; ++x)
			{
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % mod) % mod;
			}
		}
	}
	return C;
}
vector<vector<int>> pow(vector<vector<int>> A, int p) {
	if (p == 1)return A;
	if (p % 2 == 0) {
		vector<vector<int>> X = pow(A, p / 2);
		return multiply(X, X);
	} else {
		return multiply(A, pow(A, p - 1));
	}

}
int compute(int n) {
	if (n == 0)
		return 0;
	if (n <= k) {
		return b[n - 1]; //base cases
	}
	//matrix exponentiation
	vector<int> F(k + 1); //F1 vector
	for (int i = 0; i <= k; ++i)
	{
		F[i] = b[i - 1];
	}
	vector<vector<int>> T(k + 1, vector<int>(k + 1)); //transformation matrix
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (i < k) {
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}
			} else {
				T[i][j] = c[k - j];
			}
		}
	}
	T = pow(T, n - 1);
	int res = 0;
	for (int i = 1; i <= k; ++i)
	{
		res += (T[1][i] * F[i]);
	}
	return res;

}

int32_t main()
{
	c_p_c();
	int t; cin >> t;
	while (t--) {
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int num;
			cin >> num;
			b.pb(num);
		}
		for (int i = 0; i < k; ++i)
		{
			int num; cin >> num;
			c.push_back(num);

		}
		int n; cin >> n;

		cout << compute(n) << endl;

		c.clear();
		b.clear();
	}
	return 0;
}