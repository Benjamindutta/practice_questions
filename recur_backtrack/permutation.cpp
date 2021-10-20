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
void perm(char in[], int i, set<string> &s) {
	if (in[i] == '\0') {
		s.insert(in);
		return;
	}
	for (int j = i; in[j] != '\0'; ++j)
	{
		/* code */
		swap(in[i], in[j]);
		perm(in, i + 1, s);
		swap(in[j], in[i]);
	}
	return;
}

int32_t main()
{
	c_p_c();
	char in[1000];
	cin >> in;
	set<string> s;
	perm(in, 0, s);
	for (auto str : s) {
		cout << str << endl;
	}


	return 0;
}