#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll fn (int n) {
	return n * 1LL * (n + 1)/2LL;
}

int main () {
	int n;
	ll m;
	cin >> n >> m;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort(ar.begin(), ar.end(), greater<int>());

	int hi = n, lo = 1;
	int sol = -1;
	while (lo <= hi) {
		int d = lo + (hi - lo)/2;
		vector<ll> br(d);
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < d; i++) {
			pq.push(make_pair(0, i));
		}
		for (int i = 0; i < n; i++) {
			int cur, in;
			tie(cur, in) = pq.top();
			pq.pop();
			cur = -cur;
			br[in] += max(0, ar[i] - cur);
			cur++;
			pq.push(make_pair(-cur, in));
		}
		ll pp = 0;
		for (auto x : br) {
			pp += x;
		}
		if (pp >= m) {
			sol = d;
			hi = d - 1;
		} else {
			lo = d + 1;
		}
	}
	
	cout << sol << '\n';
}
