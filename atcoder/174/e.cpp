#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);
const int MAX = 1e9;

int main() {
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int arriba = MAX, abajo = 1;
	int sol = MAX;

	while (abajo <= arriba) {
		int mid = abajo + (arriba - abajo)/2;
		int cortes = 0;
		for (int i = 0; i < n; i++) {
			cortes += (ar[i] == mid ? 0 : ar[i]/mid);
		}
		
		if (cortes <= k) {
			arriba = mid - 1;
			sol = min(sol, mid);
		} else {
			abajo = mid + 1;
		}
	}

	cout << sol << '\n';

}
