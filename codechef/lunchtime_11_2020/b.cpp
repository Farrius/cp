#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x, y, n;
		cin >> x >> y >> n;
		int sol = 0;
		for (int i = 0; i <= n; i++) {
			if ((x ^ i) < (y ^ i)) sol++;
		}
		cout << sol << '\n';
	}
}
