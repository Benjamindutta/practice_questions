#include <bits/stdc++.h>
using namespace std;
bool comparetor(string str1, string str2) {
	if (str1.size() <= str2.size() && str2.substr(0, str1.size()) == str1) {return false;}
	else if (str1.size() >= str2.size() && str1.substr(0, str2.size()) == str2) {return true;}
	else return str1 < str2;
}
int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	int n; cin >> n;
	string str[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, comparetor);
	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
	return 0;
}