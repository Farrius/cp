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
		vector<pair<ll, int>> ar;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			ar.push_back({x, i});
		}
		sort(ar.begin(), ar.end());
		vector<ll> pref(n + 1);
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + ar[i - 1].first;
		}
		sort(ar.begin(), ar.end(), greater<pair<int, int>>());
		vector<ll> sol;
		sol.push_back(ar[0].second);
		for (int i = 1; i < n; i++) {
			if (pref[n - i] < ar[i - 1].first) break;
			sol.push_back(ar[i].second);
		}
		sort(sol.begin(), sol.end());
		cout << (int) sol.size() << '\n';
		for (int i = 0; i < (int) sol.size(); i++) {
			cout << sol[i] + 1 << (i == (int) sol.size() - 1 ? '\n' : ' ');
		}
	}
}
