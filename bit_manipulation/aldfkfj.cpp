#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	char mat[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((j == 0 && j < n / 2) || (i == n / 2) || (j == n / 2) || (i == 0 && j > n / 2) || (i == (n - 1) && j < n ) / 2 || (i < n / 2 && j == (n - 1))) {
				mat[i][j] = '*';
			} else {
				mat[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	return 0;
}