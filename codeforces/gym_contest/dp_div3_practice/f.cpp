#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e5 + 5;

vector<int> canons(125), dp(MX, 125);

int main () {
	int pyramid = 0;
	for (int i = 1; i < 125; i++) {
		pyramid += i;
		canons[i] += canons[i - 1] + pyramid;
	}
	dp[0] = 0;
	for (int i = 1; i < MX; i++) {
		for (int x : canons) {
			if (i - x < 0) break;
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}
