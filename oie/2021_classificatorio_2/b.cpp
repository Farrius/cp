#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll sol = -1;

ll diez[18];

ll fn (ll x) {
	ll k = x;
	vector<ll> ar;
	while (x) {
		ar.push_back(x % 10);
		x /= 10;
	}
	int m = (int) ar.size();
	bool pali = true;
	int s = 0, j = m - 1;
	while (s < j) {
		if (ar[s] != ar[j]) pali = false;
		s++;
		j--;
	}
	if (pali) sol = k;
	ll nx = 0, ny = 0;
	for (int i = 0; i < m; i++) {
		nx += ar[i] * diez[i];
		ny += ar[i] * diez[m - i - 1];
	}
	return (nx + ny)/2LL;
}

int main () {
	diez[0] = 1;
	for (int i = 1; i < 18; i++) {
		diez[i] = diez[i - 1] * 10;
	}
	int t;
	cin >> t;
	while (t--) {
		sol = -1;
		ll cur;
		cin >> cur;
		set<ll> st;
		while (true) {
			if (sol != -1 || st.count(cur)) break;
			st.insert(cur);
			cur = fn(cur);
		}
		if (sol == -1) cout << "Que complicado!" << '\n';
		else cout << sol << '\n';
	}
}
