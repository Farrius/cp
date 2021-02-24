#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int power (int n, int k) {
	int res = 1;
	while (k) {
		if (k % 2) res = (res * 1LL * n) % MOD;
		n = (n * 1LL * n) % MOD;
		k /= 2;
	}

	return res;
}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << power(a, b) << '\n';
	}
}
