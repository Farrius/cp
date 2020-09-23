#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, q;
	string s;
	cin >> n >> s >> q;

	while (q--) {
		int m;
		char c;
		cin >> m >> c;
		int sol = 0;
		
		int l = 0, r = 0;
		int seq = 0;

		while (l < n) {
			if (m < 0 || r == n) {
				seq--;
				if (s[l] != c) m++;
				l++;
			} else if (m == 0) {
				if (s[r] != c) {
					seq--;
					if (s[l] != c) m++;
					l++;
				} else {
					seq++;
					sol = max (sol, seq);
					r++;
				}
			} else {
				if (s[r] == c) {
					seq++;
					sol = max (sol, seq);
					r++;
				} else {
					seq++;
					m--;
					sol = max(sol, seq);
					r++;
				}
			}
		}

		cout << sol << '\n';
	}
}
