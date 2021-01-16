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
		int n = (int) s.size(), m = (int) t.size();
		if (n > m) {
			swap(s, t);
			swap(n, m);
		}
		bool ok = false;
		int cur = m;
		while (cur % n) {
			cur += m;
		}
		string sol;
		for (int i = 0, j = 0; i < cur; i++, j++) {
			if (j == m) j = 0;
			sol += t[j];
		}
		string cmp;
		for (int i = 0; i < cur/n; i++) {
			cmp += s;
		}
		if (cmp == sol) cout << sol << '\n';
		else cout << -1 << '\n';
	}
}
