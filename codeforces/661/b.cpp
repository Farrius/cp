#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n], br[n];
		int minia = MOD, minib = MOD;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			minia = min(minia, ar[i]);
		}

		for (int i = 0; i < n; i++) {
			cin >> br[i];
			minib = min(minib, br[i]);
		}
		ll sol = 0;

		for (int i = 0; i < n; i++) {
			int distA = ar[i] - minia;
			int distB = br[i] - minib;
			sol += max(distA, distB);
		}

		cout << sol << '\n';
	}
}
