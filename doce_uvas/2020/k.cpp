#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
int sol = 0;
int pref[MX];

void fn (int l, int r) {
	sol++;
	if (l == r) return;
	int positivos = pref[r] - pref[l - 1];
	if (positivos == 0) return;
	int dist = (r - l)/2;
	fn (l, l + dist);
	fn (l + dist + 1, r);
}

int main () {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		string s;
		cin >> s;
		memset(pref, 0, sizeof(pref));
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + (s[i - 1] == '1');
		}
		sol = 0;
		fn(1, n);
		cout << sol << '\n';
	}
}
