#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const int PI = acos((ld) - 1);

int main () {
	int n;
	cin >> n;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort (ar, ar + n);
	ll sol = INF;

	for (ll c = 1; c <= 1000000; c++) {
		ll curSol = 0, k = 1;
		for (int i = 0; i < n; i++) {
			curSol += abs(ar[i] - k);
			if (curSol >= sol) break;
			k *= c;
		}

		if (curSol >= sol) break;
		sol = curSol;
	}

	cout << sol << '\n';
}
