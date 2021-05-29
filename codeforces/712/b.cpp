#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lz = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		int ar[n], br[n], u = 0, z = 0, uu = 0, zz = 0;
		cin >> s;
		for (int i = 0; i < n; i++) {
			ar[i] = s[i] - '0';
			if (ar[i]) {
				u++;
				zz++;
			} else {
				z++;
				uu++;
			}
		}
		cin >> s;
		for (int i = 0; i < n; i++) {
			br[i] = s[i] - '0';
		}

		auto upd = [&] (int i) {
			if (ar[i] == 1) {
				u--;
				zz--;
			} else {
				z--;
				uu--;
			}
		};
		int state = 0;
		bool ok = true;
		for (int i = n - 1; i >= 0 && ok; i--) {
			if (ar[i] ^ state != br[i]) {
				state ^= 1;
				if (state == 0 && u != z) {
					ok = false;
					continue;
				}
				if (state == 1 && uu != zz) {
					ok = false;
					continue;
				}
				while (i >= 0 && ar[i] ^ state == br[i]) {
					upd(i);
					i--;
				}
				i++;
			} else {
				upd(i);
			}
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
