#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		sol += abs(ar[i] - ar[n/2]);
	}
	cout << sol << '\n';
}
