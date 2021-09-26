#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 998244353;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	if (n < m) {
		int diff = m - n;
		string c(diff, '0');
		a = c + a;
		n = m;
	}
	if (n > m) {
		int diff = n - m;
		string c(diff, '0');
		b = c + b;
		m = n;
	}

	int unos = 0;
	vector<int> bits(n);
	for (int i = 0; i < n; i++) {
		if (b[i] == '1') unos++;
		if (a[i] == '1') {
			bits[n - i - 1] = unos;
		}
	}

	int sol = 0;
	int cur = 1;
	for (int i = 0; i < n; i++) {
		int sumar = (cur * 1LL * bits[i]) % MOD;
		sol = (sol + 0LL + sumar) % MOD;
		cur = (cur * 1LL * 2) % MOD;
	}
	cout << sol << '\n';
}
