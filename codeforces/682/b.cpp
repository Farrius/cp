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
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int cur;
			cin >> cur;
			mp[cur]++;
		}
		bool ok = false;
		for (auto x : mp) {
			if (x.second > 1) ok = true;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}
