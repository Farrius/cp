#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mp[ar[i]]++;
		}
		set<int> st;
		for (auto x : mp) {
			st.insert(x.second);
		}
		int sol = 1e5 + 5;
		for (auto x : st) {
			int cur = 0;
			for (auto y : mp) {
				if (y.second >= x) cur += y.second - x;
				else cur += y.second;
			}
			sol = min(sol, cur);
		}
		cout << sol << '\n';
	}
}
