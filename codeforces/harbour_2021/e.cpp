#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> ar(n), cnt(n);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i]--;
			cnt[(i - ar[i] + n) % n]++;
		}

		vector<int> sol;
		for (int k = 0; k < n; k++) {
			if (cnt[k] >= n - 2 * m) {
				vector<int> p(n);
				for (int i = 0; i < n; i++) {
					p[(i - k + n) % n] = ar[i];
				}
				int cc = 0;
				vector<bool> vis(n);
				for (int i = 0; i < n; i++) {
					if (vis[i]) continue;
					int j = i;
					while (!vis[j]) {
						vis[j] = true;
						j = p[j];
					}
					cc++;
				}
				if (n - cc <= m) {
					sol.push_back(k);
				}
			}
		}

		cout << (int) sol.size();
		for (auto x : sol) cout << ' ' << x;	
		cout << '\n';
	}
}
