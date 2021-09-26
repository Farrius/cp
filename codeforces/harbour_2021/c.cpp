#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int fn (string s) {
	int n = (int) s.size();
	int meta = 0, metb = 0, queda = 5, quedb = 5;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (s[i] == '1') meta++;
			queda--;
			if (meta > metb + quedb || metb > meta + queda) return i + 1;
		} else {
			if (s[i] == '1') metb++;
			quedb--;
			if (metb > meta + queda || meta > metb + quedb) return i + 1;
		}
	}
	return n;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		string a, b;
		a = s;
		b = s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				if (i % 2 == 0) {
					a[i] = '1';
					b[i] = '0';
				} else {
					b[i] = '1';
					a[i] = '0';
				}
			}
		}
		cout << min(fn(a), fn(b)) << '\n';
	}
}
