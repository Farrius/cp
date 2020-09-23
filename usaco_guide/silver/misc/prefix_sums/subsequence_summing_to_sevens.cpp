#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int n;
	cin >> n;
	int pref[n + 1];
	pref[0] = 0;
	set<int> vistos = {0};
	map<int, int> index;
	int sol = 0;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		pref[i + 1] = (pref[i] + cur) % 7;

		if (vistos.count(pref[i + 1])) {
			int dist = i - index[pref[i + 1]];
			sol = max(sol, dist);
		} else {
			vistos.insert(pref[i + 1]);
			index[pref[i + 1]] = i;
		}
	}
	cout << sol << '\n';
}

