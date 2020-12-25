#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ll g = 0;
	for (int i = 1; i < n; i++) {
		g = __gcd(g, abs(ar[0] - ar[i]));
	}
	for (int i = 0; i < m; i++) {
		ll q;
		cin >> q;
		cout << __gcd(g, abs(ar[0] + q)) << ' ';
	}
	cout << '\n';
}
