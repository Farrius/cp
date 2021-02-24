#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int power (int n, ll k, int mod) {
	int res = 1;

	while (k) {
		if (k % 2) res = (res * 1LL * n) % mod;
		n = (n * 1LL * n) % mod;
		k /= 2;
	}

	return res;
}

int main () {
	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << power (a, power(b, c, MOD - 1), MOD) << '\n';
	}

}
