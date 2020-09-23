#include <bits/stdc++.h>

using namespace std;

bool cmp (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.second.first < b.second.first;
}

int  main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

	int n;
	cin >> n;
	pair<int, pair<int, int>> ar[n];

	for (int i = 0; i < n; i++) {
		int a, t;
		cin >> a >> t;
		ar[i] = {i, {a, t}};
	}
	
	sort(ar, ar + n, cmp);

	set<pair<int, pair<int, int>>> esperando;
	int tiempo = 0, sol = 0;

	int i = 0;
	
	while (esperando.size() || i < n) {
		while(i < n && ar[i].second.first <= tiempo) {
			esperando.insert(ar[i]);
			i++;
		}
		if (esperando.empty()) {
			if (tiempo < ar[i].second.first) tiempo += ar[i].second.first - tiempo;
			sol = max(sol, max(0, tiempo - ar[i].second.first));
			tiempo += ar[i].second.second;
			i++;
		} else {
			pair<int, pair<int, int>> cur = *esperando.begin();

			sol = max(sol, tiempo - cur.second.first);
			tiempo += cur.second.second;
			esperando.erase(cur);
		}
	}

	cout << sol << '\n';
}
