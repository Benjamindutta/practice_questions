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
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void generate(char *in, char *out, int j, int i) {
	if (in[i] == 0) {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int a = in[i] - '0';
	out[j] = alphabet[a - 1];
	generate(in, out, j + 1, i + 1);
	if (in[i + 1] != '\0') {
		a = in[i] - '0';
		int b = in[i + 1] - '0';
		int alpha = a * 10 + b;
		if (alpha <= 26) {
			out[j] = alphabet[alpha - 1];
			generate(in, out, j + 1, i + 2);
		}
	}

	return;
}

int32_t main()
{
	c_p_c();
	char in[1000]; cin >> in;
	char out[1000];
	generate(in, out, 0, 0);
	return 0;
}