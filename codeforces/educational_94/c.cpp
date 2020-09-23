#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		int x;
		cin >> x;
		vector<int> sol(n, -1);
		bool ok = true;

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '1') {
				bool puede = false;
				if (i + x < n && (sol[i + x] == 1 || sol[i + x] == -1)) {
					sol[i + x] = 1;
					puede = true;
				}
				
				if (!puede && ((i - x >= 0 && (sol[i - x] == 1 || sol[i - x] == -1)))) {
					sol[i - x] = 1;
					puede = true;
				}
				
				if (!puede) {
					ok = false;
					break;
				}
			} else {
				if ((i + x < n && sol[i + x] == 1) ||  (i - x >= 0 &&  sol[i - x] == 1)) {
					ok = false;
					break;
				} else {
					if (i + x < n) sol[i + x] = 0;
					if (i - x >= 0) sol[i - x] = 0;
				}
			}
		}

		if (ok) {
			for (auto x: sol) {
				if (x == -1) cout << 1;
				else cout << x;
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}

	}
}
