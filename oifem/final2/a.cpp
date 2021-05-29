#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n, greater<int>());
	int m;
	cin >> m;
	int br[m];
	for (int i = 0; i < m; i++) {
		cin >> br[i];
	}
	sort(br, br + m, greater<int>());
	int sol = 0;
	for (int u = -1; u < n; u++) {
		for (int d = -1; d < m; d++) {
			if ((u + 1) * 2 + d + 1 > 10) continue;
			int cur = 0;
			for (int i = 0; i <= u; i++) {
				cur += ar[i];
			}
			for (int j = 0; j <= d; j++) {
				cur += br[j];
			}
			sol = max(sol, cur);
		}
	}
	cout << sol << '\n';
}
