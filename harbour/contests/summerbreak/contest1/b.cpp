#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll t;
	cin >> t;
	vector<int> sol(n), ls, rs;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') rs.push_back(i);
		else ls.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			auto nxtt = upper_bound(ls.begin(), ls.end(), i);
			if (nxtt == ls.end()) {
				if (i + t < n) sol[i + t]++;
				continue;
			}
			int nxt = *nxtt;
			ll tt = t - (nxt - i);
			if (tt < 0) sol[i + t]++;
			else if (tt % 2 == 0) sol[nxt]++;
			else sol[nxt - 1]++;
		} else {
			auto nxtt= lower_bound(rs.begin(), rs.end(), i);
			if (nxtt == rs.begin()) {
				if (i - t >= 0) sol[i - t]++;
				continue;
			}
			nxtt--;
			int nxt = *nxtt;
			ll tt = t - (i - nxt);
			if (tt < 0) sol[i - t]++;
			else if (tt % 2 == 0) sol[nxt]++;
			else sol[nxt + 1]++;

		}
	}
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
