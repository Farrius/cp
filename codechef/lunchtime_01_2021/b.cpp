#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << (r + r) - (l + l) + 1 << '\n';
	}
}
