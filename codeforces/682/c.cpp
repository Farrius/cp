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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cur;
				cin >> cur;
				if ((i + j) % 2 && cur % 2 == 0) cur++;
				else if ((i + j) % 2 == 0 && cur % 2) cur++;
				cout << cur << (j == m - 1 ? '\n' : ' ');
			}
		}
	}
}
