#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	ll ar[n], br[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> br[i];
	}
	ll mx_a = 1, mx_b = 1;
	ll cur = 1;
	for (int i = 0; i < n; i++) {
		mx_a = max(mx_a, ar[i]);
		cur = max(cur, mx_a * br[i]);
		cout << cur << '\n';
	}
}
