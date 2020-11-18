#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int un = 0, zer = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				if (s[i] == '1') un++;
				else zer++;
			}
		}
		cout << max(un, zer) << '\n';
	}
}
