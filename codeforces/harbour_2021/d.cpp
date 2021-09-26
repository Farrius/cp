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
		int n = (int) s.size();
		int m = (int) t.size();
		int i = m - 1, j = n - 1;
		while (i >= 0 && j >= 0) {
			if (t[i] == s[j]) {
				i--;
				j--;
			} else {
				j -= 2;
			}
		}
		if (i == -1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
