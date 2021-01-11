#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll x, y;

map<ll, ll> memo;

ll fn (ll y) {
	if (y == 1) return abs(x - y);
	if (memo.find(y) != memo.end()) return memo[y];
	if (y % 2 == 0) {
		return memo[y] = min(fn(y/2) + 1, abs(x - y));
	} else {
		return memo[y] = min(fn(y + 1) + 1, min(fn(y - 1) + 1, abs(x - y)));
	}
}

int main () {
	cin >> x >> y;
	cout << fn(y) << '\n';
}
