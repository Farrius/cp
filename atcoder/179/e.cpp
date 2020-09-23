#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll n, x, m;
	cin >> n >> x >> m;
	set<ll> st;
	vector<ll> seq;
	ll repeat;
	while (true) {
		seq.push_back(x);
		st.insert(x);
		x = (x * x) % m;
		if (st.count(x)) {
			repeat = x;
			break;
		}
	}

	ll sol = 0;
	int i = 0;

	while (i < (int) seq.size() && seq[i] != repeat && n > 0) {
		sol += seq[i];
		i++;
		n--;
	}

	vector<ll> cycle, pref = {0};

	for (int j = i; j < (int) seq.size(); j++) {
		cycle.push_back(seq[j]);
		pref.push_back(seq[j]);
		pref.back() += pref[(int) pref.size() - 2];
	}

	sol += pref.back() * (n / (int) cycle.size());
	sol += pref[n % (int) cycle.size()];

	cout << sol << '\n';
}
