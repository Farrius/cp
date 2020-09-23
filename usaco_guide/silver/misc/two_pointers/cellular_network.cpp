#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;

	int citis[n];
	vector<int> towers(m);

	for (int i = 0; i < n; i++) {
		cin >> citis[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> towers[i];
	}
	sort (citis, citis + n);
	sort (towers.begin(), towers.end());

	int sol = INT_MIN;

	for (int i = 0; i < n; i++) {
		int index = lower_bound(towers.begin(), towers.end(), citis[i]) - towers.begin();
		if (index == m) index--;

		int dist = abs(citis[i] - towers[index]);

		if (index != m - 1) dist = min (dist, abs(citis[i] - towers[index + 1]));
		if (index != 0) dist = min (dist, abs(citis[i] - towers[index - 1]));

		sol = max(sol, dist);
	}

	cout << sol << '\n';
}

