#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<int> perf;
	for (int i = 1; i * i <= 1e9; i++) {
		perf.insert(i * i);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cuadro = 2;
		bool ok = false;
		while (cuadro <= 1e9 && n % cuadro == 0) {
			if (perf.count(n/cuadro)) {
				cout << "YES" << '\n';
				ok = true;
				break;
			}
			cuadro *= 2;
		}
		if (!ok) cout << "NO" << '\n';
	}
}
