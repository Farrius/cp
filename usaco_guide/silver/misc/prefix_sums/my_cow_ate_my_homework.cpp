#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main () {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);

	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	vector<long long> pref(n + 1);

	int mini = min(ar[n - 1], ar[n - 2]);
	pref[n - 1] = max(ar[n - 1], ar[n - 2]);

	for (int i = n - 3; i >= 0; i--) {
		if (ar[i] < mini) {
			pref[i + 1] = pref[i + 2] + mini;
			mini = ar[i];
		} else {
			pref[i + 1] = pref[i + 2] + ar[i];
		}
	}

	vector<ld> ans;
	ld maxi = 0;
	for (int i = 2; i <= n - 1; i++) {
		ld cur = (ld)pref[i]/(n - i);
		if (cur > maxi) {
			ans.clear();
			maxi = cur;
			ans.push_back(i - 1);
		} else if (cur == maxi) {
			ans.push_back(i - 1);
		}
	}

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}
