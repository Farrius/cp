#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
int w[MX];

bool cmp (const int& a, int& b) {
	return w[a] > w[b];
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll tot = 0;
		vector<int> g[n];
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			tot += w[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> ind(n), cnt(n, -1);
		for (int i = 0; i < n; i++) {
			ind[i] = i;
			cnt[i] += (int) g[i].size();
		}
		sort(ind.begin(), ind.end(), cmp);
		int j = 0;
		cout << tot << (n == 2 ? '\n' : ' ');
		for (int i = 1; i < n - 1; i++) {
			while (j < n && cnt[ind[j]] == 0) j++;
			ll cur = (j == n ? 0 : w[ind[j]]);
			tot += cur;
			cout << tot << (i == n - 2 ? '\n' : ' ');
			cnt[ind[j]]--;
		}
	}
}
