#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e15;

int main () {
	ll maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	ll sol = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ll x1 = x + y;
		ll y1 = y - x;
		sol = max (sol, maxX - x1);
		sol = max (sol, x1 - minX);
		sol = max (sol, maxY - y1);
		sol = max (sol, y1 - minY);
		maxX = max (maxX, x1);
		minX = min (minX, x1);
		maxY = max (maxY, y1);
		minY = min (minY, y1);
	}

	cout << sol << '\n';
}
