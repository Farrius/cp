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
		vector<int> cnt(n + 1);
		vector<bool> ok(n + 1);
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			ok[ar[i]] = true;
		}
		for (int i = 0; i < n; i++) {
			cnt[ar[i]]++;
			while (i < n - 1 && ar[i + 1] == ar[i]) i++;
		}
		cnt[ar[0]]--;
		cnt[ar[n - 1]]--;
		int mn = n;
		for (int i = 1; i <= n; i++) {
			if (!ok[i]) continue;
			mn = min(mn, cnt[i] + 1);
		}
		cout << mn << '\n';
	}
}
