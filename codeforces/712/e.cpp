#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n], c[n], in[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i] >> c[i];
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol += c[i];
	}
	iota(in, in + n, 0);
	sort(in, in + n, [&] (int a, int b) { return ar[a] < ar[b];});
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		mx = max(mx, ar[in[i]] + c[in[i]]);
		sol += max(0, ar[in[i + 1]] - mx);
	}
	cout << sol << '\n';
}
