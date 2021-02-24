#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	string base = "ahlo";
	while (t--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		bool ok = true;
		if ((int) s.size() == 4) {
			for (int i = 0; i < 4; i++) {
				if (s[i] != base[i]) ok = false;
			}
		} else {
			ok = false;
		}
		if (ok) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
}
