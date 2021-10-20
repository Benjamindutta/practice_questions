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
bool rat_in_maze(int sol[][10], char maze[10][10], int i, int j, int m, int n) {
	if (i == m && j == n) {
		sol[m][n] = 0;
		//print the sol
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	if (i > m || j > n) {
		return false;
	}
	if (maze[i][j] == 'x') {
		return false;
	}


	sol[i][j] = 1;
	int right = rat_in_maze(sol, maze, i, j + 1, m, n);
	int down = rat_in_maze(sol, maze, i + 1, j, m, n);
	sol[i][j] = 0;
	if (right || down) {
		return true;
	}
	return false;
}

int32_t main()
{
	c_p_c();
	char maze[10][10] = {
		"0000",
		"00xx",
		"000x",
		"0x00"
	};
	int sol[10][10] = {0};
	bool ans = rat_in_maze(sol, maze, 0, 0, 3, 3);

	return 0;
}