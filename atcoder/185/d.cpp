#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> ar(m);
	for (int i = 0; i < m; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());
	vector<int> lens;
	if (m > 0 && ar[0] != 1) lens.push_back(ar[0] - 1);
	for (int i = 1; i < m; i++) {
		lens.push_back(ar[i] - ar[i - 1] - 1);
	}
	if (m == 0) lens.push_back(n);
	else if (n - ar[m - 1] != 0) lens.push_back(n - (m > 0 ? ar[m - 1] : 0));
	int div = n;
	for (auto x : lens) {
		div = max(1, min(div, x));
	}
	int sol = 0;
	for (auto x : lens) {
		sol += max(0, (x + div - 1)/div);
	}
	cout << sol << '\n';
}
