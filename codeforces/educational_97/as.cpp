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
		if (l % (r + 1) >= (r + 2)/2) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
