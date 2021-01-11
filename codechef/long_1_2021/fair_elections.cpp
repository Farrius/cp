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
		int ar[n], br[m];
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			a += ar[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> br[i];
			b += br[i];
		}
		sort(ar, ar + n);
		sort(br, br + m, greater<int>());
		int i = 0;
		while (a <= b && i < n) {
			a += br[i] - ar[i];
			b += ar[i] - br[i];
			i++;
		}
		if (a <= b) cout << -1 << '\n';
		else cout << i << '\n';
	}
}
