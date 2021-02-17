#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e6 + 5;

int cnt[MX];

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		memset(cnt, 0, sizeof(cnt));
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		int l = 0, cur = 0, sol = 0;
		for (int r = 0; r < n; r++) {
			if (ar[r] > k) {
				l = r + 1;
				cur = 0;
				continue;
			}
			if (cnt[ar[r]] == 0) cur += ar[r];
			cnt[ar[r]]++;
			while (cur > k) {
				cnt[ar[l]]--;
				if (cnt[ar[l]] == 0) cur -= ar[l];
				l++;
			}
			sol = max(sol, r - l + 1);
		}
		cout << sol << '\n';
	}
}
