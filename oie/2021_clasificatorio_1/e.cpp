#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n % 2 != 0 && m % 2 != 0) {
			cout << "NO" << '\n';
			continue;
		} else {
			cout << "SI" << '\n';
		}
		if (n % 2 == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i % 2 == 0) cout << '.';
					else cout << '#';
				}
				cout << '\n';
			}
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (j % 2 == 0) cout << '.';
					else cout << '#';
				}
				cout << '\n';
			}
		}
	}
}
