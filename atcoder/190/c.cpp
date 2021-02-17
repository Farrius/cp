#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	int k;
	cin >> k;
	int c1[k], c2[k];
	for (int i = 0; i < k; i++) {
		cin >> c1[i] >> c2[i];
	}
	int sol = 0;
	for (int mask = 0; mask < (1<<k); mask++) {
		vector<int> dishes(n + 1);
		for (int j = 0; j < k; j++) {
			if ((mask>>j) & 1) {
				dishes[c1[j]]++;
			} else {
				dishes[c2[j]]++;
			}
		}
		int cur = 0;
		for (int i = 0; i < m; i++) {
			if (dishes[a[i]] > 0 && dishes[b[i]] > 0) cur++;
		}
		sol = max(sol, cur);
	}
	cout << sol << '\n';
}
