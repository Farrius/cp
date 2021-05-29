#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		swap(a, b);
		string s;
		cin >> s;
		int n = (int) s.size();
		bool pali = true;
		for (int i = 0; i < n/2; i++) {
			if (s[i] == '1') {
				a -= 2;
				if (s[n - i - 1] == '0') {
					pali = false;
				} else if (s[n - i - 1] == '?') {
					s[n - i - 1] = '1';
				}
			} else if (s[i] == '0') {
				b -= 2;
				if (s[n - i - 1] == '1') {
					pali = false;
				} else if (s[n - i - 1] == '?') {
					s[n - i - 1] = '0';
				}
			} else if (s[n - i - 1] == '1') {
				a -= 2;
				if (s[i] == '0') {
					pali = false;
				} else if (s[i] == '?') {
					s[i] = '1';
				}
			} else if (s[n - i - 1] == '0') {
				b -= 2;
				if (s[i] == '1') {
					pali = false;
				} else if (s[i] == '?') {
					s[i] = '0';
				}
			}
		}
		if (n % 2) {
			if (a % 2) {
				if (s[n/2] == '?') s[n/2] = '1';
				if (s[n/2] == '1') a--;
			} else {
				if (s[n/2] == '?') s[n/2] = '0';
				if (s[n/2] == '0') b--;
			}
		}
		for (int i = 0; i < n/2; i++) {
			if (s[i] == '?') {
				if (a < b) {
					b -= 2;
					s[i] = '0';
					s[n - i - 1] = '0';
				} else {
					a -= 2;
					s[i] = '1';
					s[n - i - 1] = '1';
				}
			}
		}
		if (a != 0 || b != 0) pali = false;
		if (pali) cout << s << '\n';
		else cout << -1 << '\n';
	}
}
