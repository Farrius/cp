#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll n, m, x;
		cin >> n >> m >> x;
		ll fila = (x - 1) % n;
		ll col = (x + n - 1)/n;
		ll sol = fila * m + col;
		cout << sol << '\n'; 
	}
}
