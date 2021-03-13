#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		bool ok = true;
		if (v < u) ok = false;
		int cnt = 0;
		for (int i = 0; i < 32 && ok; i++) {
			if ((u>>i) & 1) cnt++;
			if ((v>>i) & 1) cnt--;
			if (cnt < 0) ok = false;
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
