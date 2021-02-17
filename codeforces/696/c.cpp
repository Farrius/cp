#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e3 + 5;

vector<int> ar;
map<int, int> cnt;
int n, mx = 0;

vector<pair<int, int>> sol;

bool check (int i) {
	map<int, int> cur;
	cur = cnt;
	sol.clear();
	sol.push_back({mx, ar[i]});
	for (int j = 0; j < n; j++) {
		if (cur[ar[j]] == 0) continue;
		cur[ar[j]]--;
		int y = mx - ar[j];
		if (cur[y] == 0) {
			return false;
		} else {
			cur[y]--;
			mx = ar[j];
		}
		sol.push_back({ar[j], y});
	}
	return true;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ar.clear();
		cnt.clear();
		n = n * 2;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			ar.push_back(x);
			cnt[x]++;
		}
		sort(ar.begin(), ar.end(), greater<int>());
		cnt[ar[0]]--;
		bool ok = false;
		for (int i = 1; i < n; i++) {
			mx = ar[0];
			cnt[ar[i]]--;
			if (check(i)) {
				cout << "YES" << '\n';
				mx = ar[0];
				cout << mx + ar[i] << '\n';
				for (auto x : sol) {
					cout << x.first << ' ' << x.second << '\n';
				}
				ok = true;
				break;
			}
			cnt[ar[i]]++;
		}
		if (!ok) cout << "NO" << '\n';
	}
}
