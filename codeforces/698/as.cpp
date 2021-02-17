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
			int x;
			cin >> x;
			mp[x]++;
		}
		int sol = 0;
		for (auto x : mp) {
			sol = max(sol, x.second);
		}
		cout << sol << '\n';
	}
}
