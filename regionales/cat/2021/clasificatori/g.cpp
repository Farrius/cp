#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

bool perf (ll k) {
	ll a = sqrt(k);
	return a * a == k;
}

int main () {
	ll cur = 404;
	int cnt = 0;
	while (true) {
		if (cnt > 10) break;
		ll x = cur * 100 + 25;
		if (perf(x)) {
			cnt++;
			cout << cur << '\n';
		}
		cur += 404;
	}
}
