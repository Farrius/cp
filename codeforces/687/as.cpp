#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		int dig1 = max(abs(1 - r) + abs(1 - c), abs(n - r) + abs(m - c));
		int dig2 = max(abs(n - r) + abs(1 - c), abs(1 - r) + abs(m - c));
		cout << max(dig1, dig2) << '\n';
	}
}
