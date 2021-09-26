#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main () {
	int n;
	cin >> n;
	int mx = 0, mx2 = 0;
	ll tot = 0;
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first;
		ar[i].second = i;
		tot += ar[i].first;
		if (ar[i].first > mx) {
			mx2 = mx;
			mx = ar[i].first;
		} else if (ar[i].first > mx2) {
			mx2 = ar[i].first;
		}
	}

	sort(ar.begin(), ar.end());
	vector<int> sol;
	for (int i = 0; i < n - 1; i++) {
		if (tot - ar[i].first - ar[n - 1].first == ar[n - 1].first) sol.push_back(ar[i].second + 1);
	}
	if (tot - ar[n - 1].first - ar[n - 2].first == ar[n - 2].first) sol.push_back(ar[n - 1].second + 1);
	
	cout << (int) sol.size() << '\n';
	for (auto x : sol) cout << x << ' ';
	cout << '\n';
}
