#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
int main () {
	int n, t;
	cin >> n >> t;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<ll> x, y;
	for (int i = 0; i < (1<<(n/2)); i++) {
		ll sum = 0;
		for (int j = 0; j < n/2; j++) {
			if ((i>>j) & 1) {
				sum += ar[j];
			}
		}
		x.push_back(sum);
	}
	for (int i = 0; i < (1<<(n/2 + (n % 2))); i++) {
		ll sum = 0;
		for (int j = 0; j < n/2 + (n % 2); j++) {
			if ((i>>j) & 1) {
				sum += ar[j + n/2];
			}
		}
		y.push_back(sum);
	}
	sort(y.begin(), y.end());
	ll sol = 0;
	for (ll cur : x) {
		ll obj = t - cur;
		int i = upper_bound(y.begin(), y.end(), obj) - y.begin();
		if (i != 0) i--;
		if (cur + y[i] <= t) sol = max(sol, cur + y[i]);
	}
	cout << sol << '\n';
}
