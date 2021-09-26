#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18;

int main () {
	ll n;
	while (cin >> n) {
		int cnt = 0;
		while (n > 0) {
			cnt++;
			n -= 3;
			n = (n + 1)/2;
		}
		cout << cnt << '\n';
	}
}
