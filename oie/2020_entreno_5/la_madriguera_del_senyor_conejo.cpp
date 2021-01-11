#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) break;
		priority_queue<pair<int, int>> pq;
		ll sol = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			while (!pq.empty() && x > -pq.top().first) {
				sol += i - pq.top().second;
				pq.pop();
			}
			pq.push({-x, i});
		}
		while (!pq.empty()) {
			sol += n - pq.top().second;
			pq.pop();
		}
		cout << sol << '\n';
	}
}
