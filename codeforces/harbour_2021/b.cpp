#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		int n = (int) s.size();
		int m = (int) t.size();
		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			string cur;
			for (int j = i; j < n && !ok; j++) {
				cur += s[j];
				if ((int) cur.size() > m) break;
				int len = m - (int) cur.size();
				if (j - len < 0) continue;
				string ccur = cur;
				for (int k = 1; k <= len; k++) {
					ccur += s[j - k];
				}
				bool si = true;
				for (int k = 0; k < m; k++) {
					if (t[k] != ccur[k]) si = false;
				}
				if (si) ok = true;
			}
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
