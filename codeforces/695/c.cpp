#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 5e18;

int main () {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int mn1 = 1e9 + 7, mn2 = 1e9 + 7;
	ll tot = 0;
	for (int i = 0; i < n1 + n2 + n3; i++) {
		int x;
		cin >> x;
		tot += x;
		if (x <= mn1) {
			mn2 = mn1;
			mn1 = x;
		} else if (x < mn2) {
			mn2 = x;
		}
	}
	cout << tot - 2 * (mn1 + mn2) << '\n';
}
