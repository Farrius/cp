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
		int ar[n];
		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ar[i] %= m;
			cnt[ar[i]]++;
		}
		ll sol = 0;
		for (int i = 0; i < m; i++) {
			if (cnt[i] == 0) continue;
			sol++;
			if (i == 0) continue;
			int res = m - i;
			if (cnt[i] > cnt[res]) swap(cnt[i], cnt[res]);
			int equip = cnt[res] - cnt[i];
			sol += max(0, equip - 1);
			cnt[res] = 0;
		}
		cout << sol << '\n';
	}
}
