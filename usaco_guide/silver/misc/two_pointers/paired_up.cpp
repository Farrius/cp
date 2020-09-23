#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);

	int n;
	cin >> n;
	vector<pair<int, int>> vacas;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vacas.push_back(make_pair(y, x));
	}

	sort (vacas.begin(), vacas.end());

	int l = 0, r = (int) vacas.size() - 1;
	int sol = 0;
	while (l < r) {
		sol = max(sol, vacas[l].first + vacas[r].first);
		int resta = min(vacas[l].second, vacas[r].second);
		vacas[l].second -= resta;
		vacas[r].second -= resta;
		if (vacas[l].second == 0) l++;
		if (vacas[r].second == 0) r--;
	}

	cout << sol << '\n';
}
