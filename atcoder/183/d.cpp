#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.first == b.first) {
		return a.second.first < b.second.first;
	} else {
		return a.first < b.first;
	}
}

int main () {
	int n, w;
	cin >> n >> w;
	vector<pair<int, pair<int, int>>> personas;
	for (int i = 0; i < n; i++) {
		int s, t, cur;
		cin >> s >> t >> cur;
		personas.push_back(make_pair(s, make_pair(1, cur)));
		personas.push_back(make_pair(t, make_pair(-1, cur)));
	}
	sort(personas.begin(), personas.end(), cmp);
	int tot = 0;
	for (auto x : personas) {
		if (x.second.first == 1) {
			tot += x.second.second;
			if (tot > w) {
				cout << "No" << '\n';
				return 0;
			}
		} else {
			tot -= x.second.second;
		}
	}

	cout << "Yes" << '\n';
}
