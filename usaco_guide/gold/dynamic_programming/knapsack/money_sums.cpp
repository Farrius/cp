#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int main () {
	set<int> sol;

	int n;
	cin >> n;

	int ar[n], tot = 0;

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		tot += ar[i];
	}

	vector<bool> dp(MX);
	dp[0] = true;

	for (int i = 0; i < n; i++) {
		for (int j = tot; j >= ar[i]; j--) {
			dp[j] = (dp[j] || dp[j - ar[i]]);
			if (dp[j]) sol.insert(j);
		}
	}
	
	cout << (int) sol.size() << '\n';

	for (auto x: sol) {
		cout << x << ' ';
	}
}
