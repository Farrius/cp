#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int ar[MX];

int main () {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		int cur = s[i - 1] - 'A';
		ar[i] = cur;
	}
	vector<vector<int>> pref(26, vector<int>(n + 1)), suf(26, vector<int>(n + 2));
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; ) {
			pref[i][j] = pref[i][j - 1];
			if (ar[j] == i) {
				pref[i][j]++;
				while (j <= n && ar[j] >= i) {
					j++;
					pref[i][j] = pref[i][j - 1];
				}
			} else {
				j++;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = n; j >= 1; ){
			suf[i][j] = suf[i][j + 1];
			if (ar[j] == i) {
				suf[i][j]++;
				while (j >= 1 && ar[j] >= i) {
					j--;
					suf[i][j] = suf[i][j + 1];
				}
			} else {
				j--;
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		int as = 0, bs = 0;
		for (int i = 0; i < 26; i++) {
			as += pref[i][a - 1];
		}
		for (int i = 0; i < 26; i++) {
			bs += suf[i][b + 1];
		}
		cout << as + bs << '\n';
	}
}
