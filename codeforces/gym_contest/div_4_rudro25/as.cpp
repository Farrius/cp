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
		int zer = 0, un = 0;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') un++;
			else zer++;
		}
		int pos = 0;
		if (zer > un) {
			zer -= un;
			pos = zer % 4;
			if (pos == 0) cout << 'E' << '\n';
			else if (pos == 1) cout << 'S' << '\n';
			else if (pos == 2) cout << 'W' << '\n';
			else cout << 'N' << '\n';
		} else {
			un -= zer;
			pos = un % 4;
			if (pos == 0) cout << 'E' << '\n';
			else if (pos == 1) cout << 'N' << '\n';
			else if (pos == 2) cout << 'W' << '\n';
			else cout << 'S' << '\n';
		}
	}
}
