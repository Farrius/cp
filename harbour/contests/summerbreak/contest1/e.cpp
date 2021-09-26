#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
int main () {
	int n;
	cin >> n;
	int s[n], g[n], in[n], gs[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> g[i];
		gs[i] = s[i] + g[i];
		in[i] = i;
	}
	sort(in, in + n, [&] (int x, int y) {return s[x] + g[x] < s[y] + g[y];});
 
	int l = in[0], r = in[0];
	vector<int> tot(n);
	tot[in[0]] = gs[in[0]];
	for (auto i : in) {
		if (i >= l && i <= r) continue;
	}
 
	ll quitar = 0;
	for (int i = 0; i < n; i++) {
		if (tot[i] > s[i] + g[i] || s[i] > tot[i]) {
			cout << -1 << '\n';
			return 0;
		}
		if (i > 0 && abs(tot[i] - tot[i - 1]) > 1) {
			cout << - 1 << '\n';
			return 0;
		}
		quitar += tot[i] - s[i];
	}
	 
	cout << quitar << '\n';
	for (int i = 0; i < n; i++) {
		cout << tot[i] << (i == n - 1 ? '\n' : ' ');
	}
}
