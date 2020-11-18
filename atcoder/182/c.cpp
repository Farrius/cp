#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string s;
	cin >> s;
	vector<int> divs(3);
	int n = (int) s.size();
	int tot = 0;
	for (int i = 0; i < n; i++) {
		int cur = s[i] - '0';
		divs[cur % 3]++;
		tot += cur;
	}
	tot %= 3;
	if (tot == 0) {
		cout << 0 << '\n';
	} else if (tot == 1) {
		if (divs[1] > 0 && n > 1) {
			cout << 1 << '\n';
		} else if (divs[2] >= 2 && n > 2) {
			cout << 2 << '\n';
		} else {
			cout << -1 << '\n';
		}
	} else {
		if (divs[2] > 0 && n > 1) {
			cout << 1 << '\n';
		} else if (divs[1] >= 2 && n > 2) {
			cout << 2 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}
