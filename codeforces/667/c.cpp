#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		int range = y - x;
		bool busca = true;
		vector<int> res(n);
		res[n - 1] = MOD;
		for (int start = 1; start < 50 && busca; start++) {
			for (int diff = 1; diff <= range && busca; diff++) {
				bool okY = false, okX = false;
				vector<int> sol(n);
				sol[0] = start;
				if (start == x) okX = true;
				for (int i = 1; i < n; i++) {
					int cur = sol[i - 1] + diff;
					sol[i] = cur;
					if (cur == y) okY = true;
					if (cur == x) okX = true;
				}

				if (okY && okX && sol[n - 1] < res[n - 1]) {
					res = sol;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << res[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
