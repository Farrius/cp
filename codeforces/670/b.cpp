#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);
 
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
 
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
 
		sort (ar, ar + n);
		ll sol = -INF;
 
		for (int i = 0; i < n; i++) {
			sol = max (sol, ar[i] * 1LL * ar[(i + 1) % n] * ar[(i + 2) % n] * ar[(i + 3) % n] * ar[(i + 4) % n]);
		}
		cout << sol << '\n';
	}
}
