#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		//brute
		vector<int> perm(n);
		iota(perm.begin(), perm.end(), 0);
		bool ok = false;
		do {
			ll cnt = 0;
			vector<int> segs[n];
			for (int i = 0; i < n - 1; i++) {
				int x = perm[i];
				int y = perm[i + 1];
				if (x < y) swap(x, y);
				int dist = x - y;
				vector<bool> vis(n);
				ll pasa = 0;
				for (int k = 1; k < dist; k++) {
					int cur = (y + k) % n;
					for (auto acaba : segs[cur]) {
						if (acaba > x || acaba < y) {
							if (vis[acaba]) continue;
							vis[acaba] = true;
							pasa++;
						}
					}
				}
				segs[x].push_back(y);
				segs[y].push_back(x);
				if (cnt > k) break;
				cnt += pasa;
			}
			//checkeo
			if (cnt == k) {
				cout << "SI" << '\n';
				for (int i = 0; i < n; i++) {
					cout << perm[i] + 1 << (i == n - 1 ? '\n' : ' ');
				}
				ok = true;
			}
		} while (!ok && next_permutation(perm.begin(), perm.end()));

		if (!ok) cout << "NO" << '\n';
	}
}
