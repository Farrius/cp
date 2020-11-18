#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 2e5 + 5;

vector<pair<int, int>> preCalc[MX];
vector<int> primes[MX];

void preFn () {
	for (int i = 2; i < MX; i++) {
		if (preCalc[i].empty()) {
			for (int j = i; j < MX; j += i) {
				pair<int, int> cur = {i, 0};
				int q = j;
				while (q % i == 0) {
					q /= i;
					cur.second++;
				}

				preCalc[j].push_back(cur);
			}
		}
	}
}

ll fn (ll n, ll k) {
	ll res = 1;

	for (int i = 0; i < k; i++) {
		res *= n;
	}

	return res;
}

int main () {
	preFn();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < (int) preCalc[x].size(); j++) {
			primes[preCalc[x][j].first].push_back(preCalc[x][j].second);
		}
	}

	ll sol = 1;

	for (int i = 2; i < MX; i++) {
		sort(primes[i].begin(), primes[i].end());
		if ((int) primes[i].size() <= n - 2) continue;
		else if ((int) primes[i].size() == n - 1) sol *= fn(i, primes[i][0]);
		else sol *= fn(i, primes[i][1]);

	}

	cout << sol << '\n';
}
