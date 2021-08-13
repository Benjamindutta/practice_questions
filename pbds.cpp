#include<iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	PBDS p;
	p.insert(1);
	p.insert(3);
	p.insert(10);
	p.insert(15);
	p.insert(12);
	p.insert(19);
	for (int i = 0; i < p.size(); i++) {
		cout << i << "-" << *p.find_by_order(i) << endl;
	}
	cout << p.order_of_key(11) << endl;

	return 0;
}