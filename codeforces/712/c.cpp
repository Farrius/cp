#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int u = 0, z = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') u++;
			else z++;
		}
		bool ok = true;
		if (s[0] == '0' || s[n - 1] == '0') ok = false;
		if (u % 2 || z % 2) ok = false;
		if (!ok) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		vector<char> a(n, '.'), b(n, '.');
		int abre = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') continue;
			if (abre) {
				a[i] = '(';
				b[i] = ')';
			} else {
				a[i] = ')';
				b[i] = '(';
			}
			abre ^= 1;
		}
		abre = u/2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (cnt >= abre) break;
			if (s[i] == '0') continue;
			a[i] = '(';
			b[i] = '(';
			cnt++;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != '.') continue;
			a[i] = ')';
			b[i] = ')';
		}
		for (int i = 0; i < n; i++) {
			cout << a[i];
		}
		cout << '\n';
		for (int i = 0; i < n; i++) {
			cout << b[i];
		}
		cout << '\n';
	}
}
