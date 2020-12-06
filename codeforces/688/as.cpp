#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		int sol = 0;
		for (auto x : mp) {
			if (x.second > 1) sol++;
		}
		cout << sol << '\n';
	}
}
