#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main () {
	int n;
	cin >> n;
	int ar[n];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		tot += ar[i];
	}
	set<int> sol;
	vector<int> dp(1e5 + 5, -1);
	dp[0] = 1;
	for (int c : ar) {
		for (int x = tot; x >= c; x--) {
			if (dp[x - c] != -1) {
				dp[x] = 1;
				sol.insert(x);
			}
		}
	}
	cout << (int) sol.size() << '\n';
	for (auto x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}
