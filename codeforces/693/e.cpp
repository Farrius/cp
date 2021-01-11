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
		vector<int> h(n), w(n), ind(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i] >> w[i];
			if (h[i] > w[i]) swap(h[i], w[i]);
		}
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&] (int a, int b) { return h[a] < h[b];});
		int u = -1;
		vector<int> sol(n, -1);
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && h[ind[i]] == h[ind[j]]) j++;
			for (int k = i; k < j; k++) {
				if (u != -1 && w[u] < w[ind[k]]) sol[ind[k]] = u;
			}
			for (int k = i; k < j; k++) {
				if (u == -1 || w[u] > w[ind[k]]) u = ind[k];
			}
		}
		for (int i = 0; i < n; i++) {
			if (sol[i] == -1) cout << -1;
			else cout << sol[i] + 1;
			cout << (i == n - 1 ? '\n' : ' ');
		}
	}
}
