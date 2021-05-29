#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x, k;
	cin >> x >> k;
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());

	queue<pair<int, vector<int>>> q;
	pair<int, vector<int>> ex;
	ex.first = x % k;
	vector<int> exx;
	ex.second = exx;
	q.push(ex);
	int cnt = 0;
	vector<bool> vis(k);
	while (!q.empty()) {
		int res = q.front().first;
		vector<int> usados = q.front().second;
		q.pop();
		if (vis[res]) continue;
		vis[res] = true;
		if (res == 0) {
			cout << x;
			for (auto y : usados) cout << y;
			cout << '\n';
			return 0;
		}
		for (auto y : ar) {
			int nw_res = res * 10 + y;
			nw_res %= k;
			usados.push_back(y);
			q.push(make_pair(nw_res, usados));
			usados.pop_back();
		}
		cnt++;
		if (cnt > 100000) break;
	}
	cout << -1 << '\n';
}
