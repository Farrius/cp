#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int sol = 0;
		for (int i = 0; i < n;) {
			if (s[i] == '*') {
				s[i] = 'x';
				sol++;
				int mx = i;
				for (int j = 1; j <= k && i + j < n; j++) {
					if (s[i + j] == '*') mx = i + j;
				}
				if (mx == i) break;
				i = mx;
			} else {
				i++;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'x') break;
			if (s[i] == '*') {
				sol++;
				break;
			}
		}
		cout << sol << '\n';
	}
}
