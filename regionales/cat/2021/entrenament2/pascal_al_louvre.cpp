#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll d[32], t[32];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	d[0] = t[0] = 1;
	for (int i = 1; i < 32; i++) {
		d[i] = d[i - 1] * 2;
		t[i] = t[i - 1] * 3;
	}
	int k, n;
	while (cin >> k >> n) {
		if (k % 2 == 0) {
			cout << 0 << '\n';
			continue;
		} else {
			ll cur = 0;
			int dos = -1;
			for (int i = 31; i >= 0; i--) {
				if ((n>>i) & 1) {
					dos++;
					cur += t[i] * d[dos];
				}
			}
			cout << cur << '\n';
		}
	}
}
