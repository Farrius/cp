#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	pair<long long, long long> ar[m];
	
	for (int i = 0; i < m; i++) {
		cin >> ar[i].first >> ar[i].second;
	}

	sort (ar, ar + m);

	long long lo = 1, hi = 1e18;
	long long sol = 0;
	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;

		bool ok = true;
		
		long long pos = -1e18;
		long long vacas = 0;
		
		for (auto x: ar) {
			while (max(x.first, pos + mid) <= x.second) {
				pos = max(pos + mid, x.first);
				vacas++;	
				if (vacas >= n) break;
			}
			if (vacas >= n) break;
		}

		ok = vacas >= n;

		if (ok) {
			sol = max(sol, mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}

	}

	cout << sol << '\n';
}
