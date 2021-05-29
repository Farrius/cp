#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		//coger input
		int n, m;
		cin >> n >> m;
		vector<int> dispo(n, m - (m/2)), falta(n);
		vector<int> queries[m];
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int d;
				cin >> d;
				d--;
				queries[i].push_back(d);
				falta[d]++;
			}
		}
		vector<int> sol(m);
		for (int i = 0; i < m; i++) {
			int cur = -1;
			int jodido = 1e9;
			for (auto j : queries[i]) {
				if (dispo[j] == 0) continue;
				int mal = falta[j] - dispo[j];
				if (mal < jodido) {
					jodido = mal;
					cur = j;
				}
				falta[j]--;
			}
			if (cur != -1) dispo[cur]--;
			sol[i] = cur;
		}
		bool ok = true;
		for (int i = 0; i < m; i++) {
			if (sol[i] == -1) ok = false;
		}
		if (ok) {
			cout << "YES" << '\n';
			for (int i = 0; i < m; i++) {
				cout << sol[i] + 1 << (i == m - 1 ? '\n' : ' ');
			}
		} else {
			cout << "NO" << '\n';
		}
	}
}
