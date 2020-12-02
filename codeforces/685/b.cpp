#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		while (q--) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			bool ok = false;
			for (int i = 0; i < a; i++) {
				if (s[i] == s[a]) ok = true;
			}
			for (int i = b + 1; i < n; i++) {
				if (s[i] == s[b]) ok = true;
			}
			if (ok) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}
