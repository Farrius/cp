#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int j = m - 1;
	vector<int> cnt(n);
	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1) cnt[i] = cnt[i + 1];
		if (s[i] == t[j]) {
			j--;
			cnt[i]++;
		}
	}
	vector<vector<int>> posis(26, vector<int>());
	vector<int> in_pos(26);
	for (int i = 0; i < n; i++) {
		posis[s[i] - 'a'].push_back(i);
	}
	j = 0;
      	int sol = 1;
	for (int i = 0; i < n; i++) {
		if (j < m && s[i] == t[j]) {
			j++;
			if (j < m) {
				int pos = t[j] - 'a';
				int k = (int) posis[pos].size();
				int f = posis[pos][in_pos[pos]];
				while (in_pos[pos] < k && cnt[posis[pos][in_pos[pos]]] >= m - j) {
					sol = max(sol, posis[pos][in_pos[pos]] - i);
					in_pos[pos]++;
				}
			}
		}
	}
	cout << sol << '\n';
}
