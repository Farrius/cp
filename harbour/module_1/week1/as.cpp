#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	ll mn = 1e18;
	for (int i = 1; i < n; i++) {
		mn = min(mn, ar[i] - ar[i - 1]);
	}
	cout << mn << '\n';
}
