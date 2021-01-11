#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			if (s[i] == '(') {
				if (i == n - 1) ok = false;
			} else if (s[i] == ')') {
				if (i == 0) ok = false;
			}
		}
		if (n % 2 == 0 && ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
