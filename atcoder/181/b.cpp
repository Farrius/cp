#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		sol += b * (b + 1)/2 - (a - 1) * a/2;
	}
	cout << sol << '\n';
}
