#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
vector<int> y(MX), x(MX);
set<pair<int, int>> arriba;
bool visy[MX];
int n, m;
int sol = 0;

void fn (int i) {
	if (visy[i]) return;
	vector<int> recu;
	vector<pair<int, int>> quitar;
	for (auto cur : arriba) {
		if (cur.first < i) {
			quitar.push_back(cur);
			sol++;
		} else {
			if (cur.second > y[i]) {
				continue;
			} else {
				for (int j = i + 1; j <= n; j++) {
					if (cur.first >= j && cur.second <= y[j]) {
						recu.push_back(j);
					}
				}
				quitar.push_back(cur);
			}
		}
	}
	for (auto cur : quitar) {
		arriba.erase(cur);
	}
	visy[i] = true;
	for (auto j : recu) {
		fn(j);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		arriba.clear();
		for (int i = 1; i <= n; i++) {
			cin >> y[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> x[i];
			arriba.insert({x[i], i});
		}
		memset(visy, false, sizeof(visy));
		sol = 0;
		for (int i = 1; i <= n; i++) {
			if (visy[i]) continue;
			sol++;
			fn(i);
		}
		cout << sol + (int) arriba.size() << '\n';
	}
}
