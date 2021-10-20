#include<bits/stdc++.h>
using namespace std;

int main() {


	float numer = 365;
	float denom = 365;
	float prob_same = 1;
	float prob_not = 1;
	float p; cin >> p;
	int people = 1;
	if (p == 1) {
		cout << "366" << endl;
		return 0;
	}
	while (1 - prob_not < p) {
		prob_not = prob_not * (numer / denom);
		cout << "People " << people << " and probaility " << (1 - prob_not) << endl;
		numer--;
		people++;
	}
	return 0;

}