#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i]--;
		}
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (ar[i] != i) pos = i;
		}
		ld f = 1, u = 1;
		for (int i = 0; i < m; i++) {
			int x;
			ld prob;
			cin >> x >> prob;
			x--;
			if (x >= pos) f *= (u - prob);
		}
		if (pos == -1) cout << 1 << '\n';
		else cout << fixed << setprecision(6) <<  u - f << '\n';
	}
}
