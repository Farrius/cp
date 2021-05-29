#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int sol = 0;
	for (int i = 0; i < n; i++) {
		int l = i - 1, r = i + 1;
		int use = k;
		sol++;
		while (l >= 0 && r <= n - 1) {
			if (s[l] == s[r]) {
				sol++;
			} else {
				if (use == 0) break;
				sol++;
				use--;
			}
			l--;
			r++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int l = i, r = i + 1;
		int use = k;
		while (l >= 0 && r <= n - 1) {
			if (s[l] == s[r]) {
				sol++;
			} else {
				if (use == 0) break;
				sol++;
				use--;
			}
			l--;
			r++;
		}
	}
	cout << sol << '\n';
}
