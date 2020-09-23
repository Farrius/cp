#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ar[n], y[n];

		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> y[i];
		}

		sort (ar, ar + n);

		int izquierda[n], r = 0;
		for (int l = 0; l < n; l++) {
			while (r < n && ar[r] - ar[l] <= k) r++;
			izquierda[l] = r - l;
		}

		int derecha[n + 1];
		derecha[n] = 0;

		for (int i = n - 1; i >= 0; i--) {
			derecha[i] = max(derecha[i + 1], izquierda[i]);
		}

		int sol = 0;

		for (int l = 0; l < n; l++) {
			sol = max(sol, izquierda[l] + derecha[l + izquierda[l]]);
		}
		cout << sol << '\n';	
	}
}
