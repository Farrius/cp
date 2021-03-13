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
		int ar[n];
		vector<int> pref(n + 5);
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll sol = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) pref[i] += pref[i - 1];
			sol += max(0, ar[i] - pref[i] - 1);
			int cnt = pref[i] - ar[i] + 1;
			if (cnt > 0) {
				pref[i + 1] += cnt;
				pref[i + 2] -= cnt;
			}
			if (ar[i] > 1) {
				int fins = min(n - 1, i + ar[i]);
				pref[i + 2]++;
				pref[fins + 1]--;
			}
		}
		cout << sol << '\n';
	}
}
