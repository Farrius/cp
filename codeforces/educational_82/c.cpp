#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


void co (int n) {
	cout << (char) (n + 'a');
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<set<int>> cnt(26, set<int>());
		int n = (int) s.size();
		if (n == 1) {
			cout << "YES" << '\n';
			cout << "qwertyuiopasdfghjklzxcvbnm" << '\n';
			continue;
		}
		int ar[n];
		for (int i = 0; i < n; i++) {
			ar[i] = s[i] - 'a';
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) cnt[ar[i]].insert(ar[i - 1]);
			if (i < n - 1) cnt[ar[i]].insert(ar[i+ 1]);
		}
		bool ok = true;
		int cur = -1, prev = -1;
		for (int i = 0; i < 26; i++) {
			if ((int) cnt[i].size() > 2) {
			       	ok = false;
			} else if ((int) cnt[i].size() == 1) {
				cur = i;
			}
		}
		if (cur == -1) {
		       	ok = false;
		}
		if (!ok) {
			cout << "NO" << '\n';
			continue;
		}
		vector<bool> vis(26, false);
		vector<int> sol;
		bool sip = true;
		while (!vis[cur]) {
			vis[cur] = true;
			sol.push_back(cur);
			int m = (int) cnt[cur].size();
			if (m <= 1 && !sip) {
				break;
			} else {
				auto it = cnt[cur].begin();
				auto at = cnt[cur].rbegin();
				if (sip) {
					cur = *it;
				} else if (vis[*it]) {
					cur = *at;
				} else if (vis[*at]) {
					cur = *it;
				} else {
					ok = false;
					break;
				}
			}
			sip = false;
		}
		for (int i = 0; i < 26; i++) {
			if (!vis[i]) {
				sol.push_back(i);
				if ((int) cnt[i].size() != 0) {
					ok = false;
				}
			}
		}
		if (!ok) {
			cout << "NO" << '\n';
			continue;
		} else {
			cout << "YES" << '\n';
		}
		for (auto x : sol) {
			co(x);
		}
		cout << '\n';
	}
}
