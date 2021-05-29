#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		priority_queue<int> pq;
		for (auto cur : cnt) {
			pq.push(cur.second);
		}
		while ((int) pq.size() >= 2) {
			int u = pq.top();
			pq.pop();
			int d = pq.top();
			pq.pop();
			u--;
			d--;
			if (u > 0) pq.push(u);
			if (d > 0) pq.push(d);
		}
		ll sol = 0;
		while (!pq.empty()) {
			sol += pq.top();
			pq.pop();
		}
		cout << sol << '\n';
	}
}
