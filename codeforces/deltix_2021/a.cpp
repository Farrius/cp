#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		string sol;
		sol = s;
		vector<int> unos;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				for (int j = 1; j <= m; j++) {
					if (i - j < 0 && i + j >= n) break;
					if (i - j >= 0) sol[i - j] = '1';
					if (i + j < n) sol[i + j] = '1';
				}
				unos.push_back(i);
			}
		}
		for (int i = 1; i < (int) unos.size(); i++) {
			int d = unos[i] - unos[i - 1] - 1;
			if (d % 2) {
				sol[unos[i - 1] + (d + 1)/2] = '0';
			}
		}
		cout << sol << '\n';
	}
}
