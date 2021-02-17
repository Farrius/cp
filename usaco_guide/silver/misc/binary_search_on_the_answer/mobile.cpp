#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

const int MX = 1e6 + 5;

int n, l;
pair<ll, ll> ar[MX];

bool check (ld mid) {
	ld fins = 0;
	for (int i = 0; i < n; i++) {
		ll x, y;
		tie(x, y) = ar[i];
		ld delta = sqrt(mid * mid - y * y);
		if (x - delta <= fins) fins = max(fins, x + delta);
	}
	if (fins >= l) return true;
	else return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	ld hi = 1.5e9, lo = 1;
	while (hi - lo > 1e-3) {
		ld mid = (lo + hi)/2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(4) << lo << '\n';
}
