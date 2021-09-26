#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ar(n);
		vector<vector<int>> vis(MX, vector<int>(2));
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<int> in(n);
		iota(in.begin(), in.end(), 0);
		sort(in.begin(), in.end(), [&] (int a, int b) {return ar[a] < ar[b];});
		for (int i = 0; i < n; i++) {
			vis[ar[in[i]]][i % 2]++;
		}

		bool ok = true;
		for (int i = 0; i < n; i++) {
			int x = ar[i];
			if (vis[x][i % 2]) {
				vis[x][i % 2]--;
			} else {
				ok = false;
				break;
			}
		}

		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
