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
		map<int, ll> cnt;
		ll sol = 0;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			cnt[ar[i]] += n - i;
		}
		for (int i = 0; i < n; i++) {
			cnt[ar[i]] -= n - i;
			sol += (i + 1) * 1LL * cnt[ar[i]];
		}
		cout << sol << '\n';
	}
}
